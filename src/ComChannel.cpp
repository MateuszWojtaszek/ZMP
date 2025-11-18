#include "ComChannel.hpp"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

// Implementacja metod z interfejsu
void ComChannel::Init(int Socket) {
  _socket = Socket;
}

int ComChannel::GetSocket() const {
  return _socket;
}

void ComChannel::LockAccess() {
  _mutex.lock();
}

void ComChannel::UnlockAccess() {
  _mutex.unlock();
}

std::mutex& ComChannel::UseGuard() {
  return _mutex;
}

// Metody własne
bool ComChannel::OpenConnection(int port) {
  struct sockaddr_in DaneAdSerw;

  memset(&DaneAdSerw, 0, sizeof(DaneAdSerw));

  DaneAdSerw.sin_family = AF_INET;
  DaneAdSerw.sin_addr.s_addr = inet_addr("127.0.0.1");
  DaneAdSerw.sin_port = htons(port);

  _socket = socket(AF_INET, SOCK_STREAM, 0);

  if (_socket < 0) {
    cerr << "*** Blad otwarcia gniazda." << endl;
    return false;
  }

  if (connect(_socket, (struct sockaddr*)&DaneAdSerw, sizeof(DaneAdSerw)) < 0) {
    cerr << "*** Brak mozliwosci polaczenia do portu: " << port << endl;
    return false;
  }
  return true;
}

bool ComChannel::Send(const char* msg) {
  ssize_t IlWyslanych;
  ssize_t IlDoWyslania = (ssize_t)strlen(msg);

  while ((IlWyslanych =
              write(_socket, msg, static_cast<size_t>(IlDoWyslania))) > 0) {
    IlDoWyslania -= IlWyslanych;
    msg += IlWyslanych;
  }
  if (IlWyslanych < 0) {
    cerr << "*** Blad przeslania napisu." << endl;
    return false;
  }
  return true;
}

void ComChannel::Close() {
  Send("Close\n");
  close(_socket);
  _socket = 0;
}