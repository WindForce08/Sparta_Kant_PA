# Sangjun
sangjun workspace 
---
### 과제는 workspace 폴더에 있습니다 ^^

>
> 26-08-10 과제 : /workspace/06_day/clac.cpp, memmory_access.cpp

---
## requirements.txt 설치

프로젝트 폴더에서 아래 명령어를 실행하면 `requirements.txt`에 명시된 모든 패키지를 한 번에 설치합니다.

```bash
pip install -r requirements.txt
```

> 가상환경(`.venv`)을 활성화한 상태에서 실행하는 것을 권장합니다.
---
## GitHub 저장소 연결 (SSH)

### 1. Git 저장소 초기화

```bash
git init
```

### 2. 원격 저장소 연결

```bash
git remote add origin git@github.com:<GitHub_ID>/<Repository>.git
```

### 3. 연결 확인

```bash
git remote -v
```

### 4. 최초 Push

```bash
git add .
git commit -m "Initial commit"
git branch -M main
git push -u origin main
```

> 이후부터는 `git push`와 `git pull`만 사용하면 됩니다.





---
# GitHub 저장소 연결 및 브랜치 작업 가이드

## 1. 저장소 Clone

```bash
git clone git@github.com:<GitHub_ID>/<Repository>.git
```

저장소로 이동합니다.

```bash
cd <Repository>
```

---

## 2. 원격 저장소 확인

```bash
git remote -v
```

출력 예시

```text
origin  git@github.com:<GitHub_ID>/<Repository>.git (fetch)
origin  git@github.com:<GitHub_ID>/<Repository>.git (push)
```

---

## 3. 최신 코드 가져오기

작업 시작 전 항상 최신 코드를 받아옵니다.

```bash
git pull origin main
```

---

## 4. 브랜치 생성 및 이동

새로운 기능이나 과제 작업은 브랜치를 생성하여 진행합니다.

```bash
git checkout -b <branch-name>
```

예시

```bash
git checkout -b feature/login
```

---

## 5. 작업 내용 저장

```bash
git add .
git commit -m "Commit message"
```

---

## 6. 브랜치 Push

처음 Push할 때

```bash
git push -u origin <branch-name>
```

예시

```bash
git push -u origin feature/login
```

이후에는

```bash
git push
```

만 입력하면 됩니다.

---

## 7. main 브랜치로 복귀

```bash
git checkout main
```

최신 코드 동기화

```bash
git pull origin main
```

---

## 8. 브랜치 목록 확인

```bash
git branch
```

원격 브랜치 포함

```bash
git branch -a
```

---

## 9. 브랜치 삭제

로컬 브랜치 삭제

```bash
git branch -d <branch-name>
```

원격 브랜치 삭제

```bash
git push origin --delete <branch-name>
```
---
# Python 가상환경(.venv) 및 Jupyter Notebook 사용 가이드

## 1. 가상환경 생성

```bash
python3 -m venv .venv
```

---

## 2. 가상환경 활성화

```bash
source .venv/bin/activate
```

활성화되면 터미널 앞에 `(.venv)`가 표시됩니다.

---

## 3. 패키지 설치

```bash
pip install -r requirements.txt
```

또는 필요한 패키지를 직접 설치합니다.

```bash
pip install numpy matplotlib pandas jupyter
```

---

## 4. 설치 패키지 저장

```bash
pip freeze > requirements.txt
```

---

## 5. Jupyter Notebook 실행

```bash
jupyter notebook
```

또는

```bash
jupyter lab
```

---

## 6. VS Code에서 Notebook 사용

프로젝트 폴더를 VS Code로 엽니다.

```bash
code .
```

`.ipynb` 파일을 생성한 후 **Kernel → `.venv`**를 선택합니다.

---

## 7. 가상환경 비활성화

```bash
deactivate
```

---



