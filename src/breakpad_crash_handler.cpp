// Copyright 2018 Xu Shaohua <xushaohua2016@outlook.com>
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "breakpad_crash_handler.h"

#include <QDebug>
#include <QDir>

#include "third_party/breakpad/src/client/minidump_file_writer.h"
#include "third_party/breakpad/src/client/linux/handler/exception_handler.h"
#include "third_party/breakpad/src/client/linux/handler/minidump_descriptor.h"

namespace blade {

struct BreakpadCrashHandlerPrivate {
  QString dump_path;
  google_breakpad::ExceptionHandler* exception_handler_ = nullptr;
};

BreakpadCrashHandler::BreakpadCrashHandler()
    : p_(new BreakpadCrashHandlerPrivate()) {
}

BreakpadCrashHandler::~BreakpadCrashHandler() {
  if (p_ != nullptr) {
    if (p_->exception_handler_ != nullptr) {
      delete p_->exception_handler_;
      p_->exception_handler_ = nullptr;
    }
    delete p_;
    p_ = nullptr;
  }
}

void BreakpadCrashHandler::setDumpPath(const QString& path) {
  p_->dump_path = path;
  if (p_->exception_handler_ != nullptr) {
    delete p_->exception_handler_;
    p_->exception_handler_ = nullptr;
  }

  QDir dir(path);
  if (!dir.exists()) {
    if (!dir.mkpath(".")) {
      qCritical() << Q_FUNC_INFO << "Failed to create folder:" << path;
    }
  }

  const google_breakpad::MinidumpDescriptor descriptor(path.toStdString());
  p_->exception_handler_ = new google_breakpad::ExceptionHandler(
      descriptor,
      nullptr,
      nullptr,
      nullptr,
      true,
      -1);
}

const QString& BreakpadCrashHandler::dumpPath() const {
  return p_->dump_path;
}

}  // namespace blade