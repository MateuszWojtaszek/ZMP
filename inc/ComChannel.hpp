#pragma once
#include <mutex>
#include "AbstractComChannel.hh"

class ComChannel : public AbstractComChannel {
  int _socket = 0;
  std ::mutex _mutex;

 public:
  bool OpenConnection(int port);
  bool Send(const char* msg);
  void Close();
  void Init(int Socket) override;
  int GetSocket() const override;
  void LockAccess() override;
  void UnlockAccess() override;
  std::mutex& UseGuard() override;
};