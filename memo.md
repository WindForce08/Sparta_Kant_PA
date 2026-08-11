---
$ sudo apt install -y build-essential cmake gdb valgrind git

$ g++ --version
g++ (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ cmake --version
cmake version 3.22.1

CMake suite maintained and supported by Kitware (kitware.com/cmake).

$ gdb --version
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

$ valgrind --version
valgrind-3.18.1
pa31@pa31-Legion-Pro-5-16IAX10:~/Sparta$ 
---


# VS Code + C++ 개발 환경 정리

> 작성 기준: 2026-08-10  
> 대상 환경: Ubuntu + VS Code + C/C++ 확장  
> 주요 프로젝트 경로 예시: `/home/pa31/Sparta/workspace/06_day`

---

## 1. VS Code 자주 사용하는 단축키

### 1.1 실행 / 디버깅

| 기능 | 단축키 | 설명 |
|---|---|---|
| 디버깅 실행 | `F5` | 프로그램을 빌드하고 디버거와 함께 실행 |
| 디버깅 없이 실행 | `Ctrl + F5` | 디버거 없이 실행 |
| 실행/디버깅 중단 | `Shift + F5` | 현재 실행 종료 |
| Step Over | `F10` | 현재 줄 실행 후 다음 줄 |
| Step Into | `F11` | 함수 내부로 진입 |
| Step Out | `Shift + F11` | 현재 함수에서 빠져나옴 |
| 빌드 | `Ctrl + Shift + B` | VS Code에 설정된 Build Task 실행 |

### 1.2 터미널

| 기능 | 단축키 |
|---|---|
| 터미널 열기/닫기 | ``Ctrl + ` `` |
| 터미널/패널 관련 명령 | `Ctrl + Shift + ` 등 |

Ubuntu에서 개발할 때 ``Ctrl + ` ``는 매우 자주 사용하게 된다.

### 1.3 코드 편집

| 기능 | 단축키 |
|---|---|
| 저장 | `Ctrl + S` |
| 실행 취소 | `Ctrl + Z` |
| 다시 실행 | `Ctrl + Y` |
| 주석 처리 | `Ctrl + /` |
| 현재 줄 복제 | `Shift + Alt + ↓` |
| 현재 줄 위/아래 이동 | `Alt + ↑ / ↓` |
| 현재 줄 삭제 | `Ctrl + Shift + K` |
| 자동 포맷팅 | `Shift + Alt + F` |
| 빠른 수정 | `Ctrl + .` |
| 이름 변경 | `F2` |

### 1.4 검색 / 탐색

| 기능 | 단축키 |
|---|---|
| 파일 내 검색 | `Ctrl + F` |
| 프로젝트 전체 검색 | `Ctrl + Shift + F` |
| 파일 빠르게 열기 | `Ctrl + P` |
| 명령 팔레트 | `Ctrl + Shift + P` |
| 심볼/함수 찾기 | `Ctrl + Shift + O` |
| 정의로 이동 | `F12` |
| 정의 미리보기 | `Alt + F12` |
| 이전 위치 | `Alt + ←` |
| 다음 위치 | `Alt + →` |

특히 `Ctrl + Shift + P`는 VS Code의 명령 팔레트를 열어 단축키를 몰라도 기능을 검색해서 실행할 수 있다.

예:

```text
Ctrl + Shift + P
→ Format Document
```

### 1.5 화면 / 개발 기능

| 기능 | 단축키 |
|---|---|
| 사이드바 | `Ctrl + B` |
| Explorer | `Ctrl + Shift + E` |
| Search | `Ctrl + Shift + F` |
| Source Control | `Ctrl + Shift + G` |
| Run & Debug | `Ctrl + Shift + D` |
| Extensions | `Ctrl + Shift + X` |
| 설정 | `Ctrl + ,` |
| 에디터 분할 | `Ctrl + \` |
| 에디터 그룹 이동 | `Ctrl + 1 / 2 / 3` |

### 1.6 다중 커서 / 선택

| 기능 | 단축키 |
|---|---|
| 다중 커서 | `Alt + 클릭` |
| 같은 단어 다음 항목 선택 | `Ctrl + D` |
| 같은 단어 모두 선택 | `Ctrl + Shift + L` |

---

## 2. Python / Jupyter 관련 단축키

VS Code Notebook을 사용할 경우:

| 기능 | 단축키 |
|---|---|
| 셀 실행 후 다음 셀 | `Shift + Enter` |
| 현재 셀 실행 | `Ctrl + Enter` |
| 아래 셀 추가 | `B` |
| 위 셀 추가 | `A` |
| 셀 삭제 | `D` 두 번 (`DD`) |

---

# 3. C++ 빌드 오류 분석

## 3.1 발생한 오류

C++ 파일:

```text
/home/pa31/Sparta/workspace/06_day/Hello_World.cpp
```

빌드 시 VS Code가 다음 명령을 실행했다.

```bash
/usr/bin/gcc -fdiagnostics-color=always -g \
/home/pa31/Sparta/workspace/06_day/Hello_World.cpp \
-o /home/pa31/Sparta/workspace/06_day/Hello_World
```

그리고 다음과 같은 오류가 발생했다.

```text
undefined reference to `std::cout'
undefined reference to `std::endl'
undefined reference to `std::ios_base::Init::Init()'
```

## 3.2 원인

`Hello_World.cpp`는 C++ 프로그램이고 `std::cout`, `std::endl`, `<iostream>` 등을 사용한다.

그런데 VS Code의 Build Task가 C++ 파일을 다음처럼 `gcc`로 빌드하고 있었다.

```text
gcc
```

C++에서는 일반적으로 다음을 사용해야 한다.

```text
g++
```

### 컴파일러 구분

```text
.c       → gcc
.cpp     → g++
```

`gcc`로 `.cpp`를 처리하면 컴파일 과정 이후 C++ 표준 라이브러리(`libstdc++`) 링크가 자동으로 제대로 처리되지 않아 `std::cout` 등의 `undefined reference` 오류가 발생할 수 있다.

---

# 4. VS Code `tasks.json` 수정

## 4.1 기존 설정

기존 `tasks.json`에는 다음과 같은 부분이 있었다.

```json
"label": "C/C++: gcc 활성 파일 빌드",
"command": "/usr/bin/gcc",
```

## 4.2 수정

다음처럼 변경한다.

```json
"label": "C/C++: g++ 활성 파일 빌드",
"command": "/usr/bin/g++",
```

전체 예시는 다음과 같다.

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ 활성 파일 빌드",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "디버거에서 생성된 작업입니다."
        }
    ],
    "version": "2.0.0"
}
```

### 주의

다음 설정:

```json
"problemMatcher": [
    "$gcc"
]
```

는 그대로 둬도 된다.

`$gcc`는 컴파일러를 gcc로 선택한다는 뜻이 아니라 VS Code가 컴파일 오류/경고를 인식하기 위한 문제 패턴이다.

핵심 변경 사항은:

```text
/usr/bin/gcc
      ↓
/usr/bin/g++
```

이다.

수정 후:

```text
Ctrl + S
Ctrl + Shift + B
```

로 빌드한다.

---

# 5. C++ 직접 컴파일 명령어

사용한 명령어:

```bash
g++ -Wall -Wextra -std=c++17 -o hello ./Hello_World.cpp
```

이 명령은 다음 의미를 가진다.

```text
g++                         C++ 컴파일러
-Wall                       주요 경고 활성화
-Wextra                     추가 경고 활성화
-std=c++17                  C++17 표준 사용
-o hello                    출력 실행 파일 이름을 hello로 지정
./Hello_World.cpp           현재 디렉터리의 Hello_World.cpp
```

## 5.1 `g++`

GNU C++ 컴파일러.

```bash
g++ Hello_World.cpp -o hello
```

처럼 C++ 소스 파일을 컴파일할 때 사용한다.

## 5.2 `-Wall`

주요 컴파일 경고를 활성화한다.

예를 들어 사용하지 않는 변수 등 잠재적인 문제를 경고해 줄 수 있다.

`-Wall`은 일반적으로 오류를 발생시키는 옵션이 아니라 경고를 더 많이 표시하기 위한 옵션이다.

## 5.3 `-Wextra`

`-Wall`에 더해 추가적인 경고를 활성화한다.

따라서 다음 조합이 흔히 사용된다.

```bash
-Wall -Wextra
```

## 5.4 `-std=c++17`

C++17 표준을 사용하도록 지정한다.

C++에는 여러 표준이 존재한다.

```text
C++11
C++14
C++17
C++20
C++23
...
```

## 5.5 `-o hello`

`-o`는 출력 파일 이름을 지정한다.

```bash
-o hello
```

는 컴파일 결과를 `hello`라는 이름으로 만들라는 의미다.

컴파일 후:

```text
Hello_World.cpp
hello
```

와 같은 구조가 된다.

## 5.6 `./Hello_World.cpp`

`./`는 현재 디렉터리를 의미한다.

예를 들어 현재 위치가:

```text
/home/pa31/Sparta/workspace/06_day
```

라면:

```bash
./Hello_World.cpp
```

는:

```text
/home/pa31/Sparta/workspace/06_day/Hello_World.cpp
```

를 의미한다.

---

# 6. 컴파일과 실행의 차이

다음 명령:

```bash
g++ -Wall -Wextra -std=c++17 -o hello ./Hello_World.cpp
```

는 **컴파일만 한다.**

실행은 별도로 한다.

```bash
./hello
```

전체 과정:

```text
Hello_World.cpp
      ↓
     g++
      ↓
   hello
      ↓
   ./hello
      ↓
   프로그램 실행
```

즉:

```bash
# 1. 컴파일
g++ -Wall -Wextra -std=c++17 -o hello Hello_World.cpp

# 2. 실행
./hello
```

---

# 7. 직접 `g++`로 하는 것과 VS Code `F5`의 차이

## 7.1 F5

`F5`는 VS Code의 **디버깅 실행**이다.

일반적인 흐름:

```text
F5
 ↓
설정된 빌드 작업 실행
 ↓
실행 파일 생성
 ↓
디버거 연결
 ↓
프로그램 실행
```

중단점(Breakpoint)을 걸어놓으면 특정 줄에서 프로그램을 멈출 수 있다.

```text
F10             다음 줄 실행 (Step Over)
F11             함수 내부 진입 (Step Into)
Shift + F11     함수에서 빠져나오기 (Step Out)
```

변수 값도 디버거에서 확인할 수 있다.

## 7.2 직접 `g++`

```bash
g++ -Wall -Wextra -std=c++17 -o hello Hello_World.cpp
```

는 **내가 컴파일 조건을 직접 지정해서 컴파일하는 명령**이다.

실행은:

```bash
./hello
```

로 별도로 한다.

---

# 8. F5와 `g++` 비교

| 항목 | `F5` | 직접 `g++` |
|---|---|---|
| 컴파일 | 설정에 따라 수행 | 수행 |
| 실행 | ✅ | 별도 실행 필요 |
| 디버거 | ✅ | 기본적으로 없음 |
| 중단점 | ✅ | ❌ |
| 변수 확인 | ✅ | ❌ |
| 컴파일 옵션 직접 지정 | 설정에 따라 | ✅ |
| 실제 컴파일 명령 이해 | 상대적으로 낮음 | 높음 |
| 터미널에서 독립 실행 | ❌ | ✅ |

### 핵심

```text
F5
→ "VS Code야, 설정된 방식으로 컴파일하고 디버거까지 붙여서 실행해줘."

g++
→ "내가 지정한 조건으로 C++ 프로그램을 컴파일해줘."
```

따라서 일상적인 코딩에서는 `F5`를 사용해도 된다.

다만 C++ 학습 과정에서는 직접 `g++` 명령을 사용해 보면서 **컴파일 → 링크 → 실행** 과정을 이해하는 것이 도움이 된다.

---

# 9. 현재 VS Code C++ 작업 흐름

현재 환경에서는 다음 흐름을 권장한다.

## 일반적인 개발

```text
코드 작성
   ↓
Ctrl + S
   ↓
F5
   ↓
디버깅 실행
```

## 빌드만 확인

```text
Ctrl + Shift + B
```

현재 `tasks.json`이 `g++`를 사용하도록 설정되어 있어야 한다.

## 터미널에서 직접 확인

```bash
g++ -Wall -Wextra -std=c++17 -o hello Hello_World.cpp
./hello
```

---

# 10. Python `venv` 자동 활성화 문제

VS Code 터미널을 열 때 Python 가상환경이 자동으로 활성화되는 경우가 있었다.

예:

```bash
(venv) pa31@pa31-Legion-Pro-5...
```

이는 VS Code Python 확장이 터미널을 열면서 Python 환경을 자동 활성화하는 기능 때문일 수 있다.

## 자동 활성화 끄기

VS Code 설정에서:

```text
Ctrl + ,
```

설정을 열고 검색:

```text
python terminal activate environment
```

다음 설정을 찾는다.

```text
Python › Terminal: Activate Environment
```

체크를 해제하면 VS Code 터미널을 열 때 Python `venv`가 자동으로 활성화되지 않는다.

### 중요한 점

이 설정은 `venv` 자체를 삭제하거나 사용할 수 없게 만드는 것이 아니다.

자동 활성화만 끄는 것이다.

필요할 때는 직접:

```bash
source venv/bin/activate
```

하면 된다.

---

# 11. VS Code에서 우선 익힐 단축키

처음부터 모든 단축키를 외울 필요는 없다.

## 1단계

```text
Ctrl + S           저장
Ctrl + F           파일 내 검색
Ctrl + P           파일 빠르게 열기
Ctrl + Shift + P   명령 팔레트
Ctrl + `           터미널
Ctrl + /           주석
Ctrl + Z           실행 취소
Ctrl + Shift + K   줄 삭제
```

## 2단계

```text
F5                 디버깅 실행
Ctrl + F5          디버깅 없이 실행
Shift + F5         실행 중단

F12                정의로 이동
F2                 이름 변경
Ctrl + .           빠른 수정
Shift + Alt + F    코드 포맷팅

Shift + Alt + ↓    줄 복제
Alt + ↑ / ↓        줄 이동
Ctrl + D            동일 단어 선택
```

## 3단계

```text
Ctrl + Shift + E   Explorer
Ctrl + Shift + F   전체 검색
Ctrl + Shift + G   Git
Ctrl + Shift + D   Debug
Ctrl + Shift + X   Extensions

Alt + 클릭         다중 커서
Ctrl + \           에디터 분할
Ctrl + 1/2/3       에디터 그룹 전환
```

---

# 12. 핵심 개념 요약

## C와 C++ 컴파일러

```text
C   → gcc
C++ → g++
```

## C++ 프로그램의 기본 과정

```text
.cpp 소스 코드
     ↓
   컴파일
     ↓
오브젝트 코드/링킹
     ↓
실행 파일
     ↓
   실행
```

## 직접 명령어

```bash
g++ -Wall -Wextra -std=c++17 -o hello Hello_World.cpp
./hello
```

## VS Code

```text
Ctrl + Shift + B → 빌드
F5                → 디버깅 실행
Ctrl + F5         → 디버깅 없이 실행
```

## 현재 Build Task의 핵심 설정

```json
"command": "/usr/bin/g++"
```

## 가장 중요한 구분

```text
g++ 명령어
→ 컴파일 조건과 결과물을 직접 제어

F5
→ VS Code가 설정에 따라 빌드 + 디버깅 + 실행
```

---

# 13. 현재 환경에서 기억할 최소 명령어 세트

```bash
# C++ 컴파일
g++ -Wall -Wextra -std=c++17 -o hello Hello_World.cpp

# 실행
./hello

# Python 가상환경 수동 활성화
source venv/bin/activate

# Git 상태 확인
git status
```

VS Code에서는:

```text
Ctrl + S           저장
Ctrl + Shift + B   빌드
F5                 디버깅 실행
Ctrl + F5          일반 실행
Ctrl + `           터미널
Ctrl + Shift + P   명령 팔레트
Ctrl + P           파일 찾기
```

bashrc 폴더를 업데이트 한다는 것은?

ros 도메인이란?
> 지정하지 않으면 충돌남

