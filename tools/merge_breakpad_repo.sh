#!/usr/bin/env bash
# Copyright 2018 Xu Shaohua <xushaohua2016@outlook.com>
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


SRC=breakpad/src
TARGET=src/third_party/breakpad

#mv "${SRC}" "${TARGET}"
cd "${TARGET}"
rm -rvf .git \
  src/build \
  src/client/mac \
  src/client/apple \
  src/client/ios \
  src/client/solaris \
  src/client/windows \
  src/processor/testdata \
  src/testing \
  src/third_party/lss/.git \
  src/third_party/protobuf/protobuf/.git \
  src/third_party/protobuf/protobuf/benchmarks \
  src/third_party/protobuf/protobuf/editors \
  src/third_party/protobuf/protobuf/examples \
  src/third_party/protobuf/protobuf/java \
  src/third_party/protobuf/protobuf/more_tests \
  src/third_party/protobuf/protobuf/python \
  src/third_party/protobuf/protobuf/m4 \
  src/third_party/protobuf/protobuf/src/google/protobuf/compiler/java \
  src/third_party/protobuf/protobuf/src/google/protobuf/compiler/python \
  src/third_party/protobuf/protobuf/vsprojects \
  src/tools/gyp