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

#ifndef BLADE_BREAKPAD_CRASH_HANDLER_H
#define BLADE_BREAKPAD_CRASH_HANDLER_H

#include <QStringList>

namespace blade {

struct BreakpadCrashHandlerPrivate;

/**
 *
 */
class BreakpadCrashHandler {
 public:
  explicit BreakpadCrashHandler();

  ~BreakpadCrashHandler();

  /**
   *
   * @param path
   */
  void setDumpPath(const QString& path);

  /**
   *
   * @return
   */
  const QString& dumpPath() const;

 private:
  BreakpadCrashHandlerPrivate* p_ = nullptr;
};

}  // namespace blade

#endif //BLADE_BREAKPAD_CRASH_HANDLER_H
