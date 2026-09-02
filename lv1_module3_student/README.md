# Lv.1 모듈 ③ 과제 — 로봇 좌표 변환 수학 라이브러리 (학생 배포본)

과제 지시문 `과제3_좌표변환_수학라이브러리.md` 를 푸는 **작업 폴더**입니다.
노트북에는 문제 설명과 빈 템플릿만 들어 있고, `src/` 와 `tests/` 에는
함수 이름·docstring·`TODO` 만 있습니다. **내용은 직접 채워 넣습니다.**

> **환경 규격**: Python 3.10 이상 · **표준 venv 가상환경** (Anaconda 사용 안 함) · JupyterLab 4.0 이상
> **난수 시드**: 모든 난수는 `np.random.default_rng(42)` 로 고정합니다. 시드가 다르면 제출 수치가 채점 기준과 달라집니다.

---

## 0. 사전 확인 — Python 이 있는가

```powershell
python --version
```

`Python 3.10.x` 이상이 나오면 됩니다. 안 나오거나 버전이 낮으면
[python.org/downloads](https://www.python.org/downloads/) 에서 설치하세요.
설치할 때 **"Add python.exe to PATH"** 를 반드시 체크합니다.

Windows 에 여러 버전이 깔려 있다면 런처로 확인·선택할 수 있습니다.

```powershell
py -0p                 # 설치된 버전 목록과 경로
py -3.12 --version     # 특정 버전 지정 실행
```

> **Anaconda 를 쓰지 않는 이유** — 이 과정은 이후 ROS 2 와 붙습니다.
> conda 환경은 시스템 Python 과 라이브러리 경로가 섞여 ROS 2 패키지 빌드에서
> 충돌이 잦습니다. 표준 `venv` 는 폴더 하나(`.venv/`)만 만들고, 지울 때도
> 폴더만 지우면 되므로 재현·정리가 쉽습니다.

---

## 1. venv 가상환경 만들기

이 README 가 있는 폴더에서:

### Windows (PowerShell)

```powershell
python -m venv .venv
.\.venv\Scripts\Activate.ps1
```

프롬프트 앞에 `(.venv)` 가 붙으면 활성화된 것입니다.

`Activate.ps1` 실행이 **정책 때문에 막히면** 현재 세션에만 허용해 줍니다.

```powershell
Set-ExecutionPolicy -Scope Process -ExecutionPolicy RemoteSigned
.\.venv\Scripts\Activate.ps1
```

> cmd.exe 를 쓴다면 `.venv\Scripts\activate.bat`,
> Git Bash 라면 `source .venv/Scripts/activate` 입니다.

### macOS / Linux

```bash
python3 -m venv .venv
source .venv/bin/activate
```

### 활성화 확인

```powershell
python -c "import sys; print(sys.executable)"
```

경로가 이 폴더의 `.venv` 안을 가리켜야 합니다. 시스템 Python 경로가 나오면 활성화가 안 된 것입니다.

---

## 2. 패키지 설치 (JupyterLab 포함)

```powershell
python -m pip install --upgrade pip
pip install -r requirements.txt
```

| 패키지 | 용도 |
|---|---|
| `numpy` | 배열·행렬 연산 (핵심 선형대수는 직접 구현하고, `np.linalg` 는 검산용) |
| `matplotlib` | 3D 좌표계·회전 궤적·오차 그래프 시각화 |
| `scipy` | 문제 6 의 쿼터니언 비교 대상 (`scipy.spatial.transform.Rotation`) |
| `pytest` | 문제 3·5 의 검증 테스트 |
| `jupyterlab` | 노트북 작성·실행 환경 |

설치 확인:

```powershell
python -c "import numpy, scipy, matplotlib, pytest; print(numpy.__version__, scipy.__version__, matplotlib.__version__)"
jupyter lab --version
```

---

## 3. JupyterLab 실행

가상환경이 활성화된 상태에서:

```powershell
jupyter lab
```

브라우저가 자동으로 안 열리면 터미널에 찍힌 `http://localhost:8888/lab?token=...` 주소를 복사해 넣으세요.

왼쪽 파일 브라우저에서 `notebooks/` 를 열고 `01_vectors.ipynb` 부터 순서대로 진행합니다.
**커널이 `.venv` 를 가리키는지 확인하세요.** 가상환경 안에서 `jupyter lab` 을 실행했다면 자동으로 잡힙니다.

종료는 터미널에서 `Ctrl+C` 를 두 번 누릅니다.

---

## 4. 어떻게 진행하나

노트북은 문항마다 **(1) 설명 마크다운 → (2) 코드 셀 → (3) 검증 셀** 순서로 비어 있습니다.

1. **설명 마크다운**을 읽고 무엇을 만들어야 하는지 파악합니다.
   `___` 로 비어 있는 칸은 **직접 관찰하거나 설명해서 채우는 자리**입니다.
2. `src/*.py` 의 해당 함수를 구현합니다.
   docstring 에 적힌 입력·출력·예외 계약을 그대로 지키세요. 검증 셀과 `tests/` 가 그 계약을 기준으로 돕니다.
   구현을 마치면 `raise NotImplementedError(...)` 줄을 지웁니다.
3. **코드 셀**의 `TODO` 를 채워 결과를 출력합니다.
4. **검증 셀**의 `TODO` 를 채웁니다. 각 검증 셀은 `True` 또는 통과 메시지를 출력해야 합니다.
   비교는 부동소수점 오차를 고려해 `np.allclose` / `np.isclose` 로 합니다.
5. 마지막 **답안 템플릿** 셀의 `___` 를 계산한 값과 설명으로 채웁니다.

노트북을 수정하면 `src/` 를 다시 불러와야 반영됩니다. 커널을 재시작하거나
아래 두 줄을 첫 셀에 넣어 두면 편합니다.

```python
%load_ext autoreload
%autoreload 2
```

### 공통 규칙

- **선형대수 핵심 연산은 직접 구현**합니다. `np.linalg` 는 **검산용으로만** 쓰고,
  쓸 때마다 `# 검산용` 주석을 남기세요.
  단 `matrix_rank`, `det`, `solve`, `lstsq` 는 문제 4·5 에서 **비교 대상**으로 사용합니다.
  `np.linalg.eig` 는 문제 6 의 회전축 복원에 직접 사용합니다.
- 난수는 전부 `np.random.default_rng(42)`.
- 문제 2·5·6 은 **그림이 반드시 포함**되어야 합니다 (순서 의존성 비교 그림 등).

---

## 5. 폴더 구조

```
lv1_module3_student/
├── README.md              # 이 문서
├── requirements.txt
├── notebooks/             # 문제별 노트북 6개 (문제 + 빈 템플릿)
│   ├── 01_vectors.ipynb          문제 1 — 내적·외적·정사영·rank
│   ├── 02_rotation.ipynb         문제 2 — 회전 행렬과 합성 순서
│   ├── 03_reorthogonalize.ipynb  문제 3 — 재직교화와 pytest
│   ├── 04_linear_system.ipynb    문제 4 — 가우스 소거·rank·역행렬
│   ├── 05_transform.ipynb        문제 5 — 4x4 동차변환과 최소자승법
│   └── 06_chain.ipynb            문제 6 — 좌표 변환 체인과 회전축 복원
├── src/                   # 여기를 채웁니다 (모듈 ④ 미니 프로젝트에서 그대로 import)
│   ├── __init__.py
│   ├── vectors.py                내적·정사영·skew·rank·det·가우스 소거
│   ├── rotation.py               rot_x/y/z·로드리게스·Gram-Schmidt·축각 복원
│   ├── transform.py              make_T·inv_T·점군 변환·최소자승법
│   └── coordinate_chain.py       CoordinateChain (TF2 축소판)
└── tests/                 # 여기도 채웁니다
    ├── conftest.py               프로젝트 루트를 import 경로에 추가 (수정 불필요)
    ├── test_rotation.py          문제 3 — 회전행렬 성질 4가지 이상
    └── test_transform.py         문제 5 — inv_T 검증
```

함수 이름과 반환 형식은 **바꾸지 마세요.** 모듈 ④ 미니 프로젝트에서 이 패키지를 그대로 import 합니다.

---

## 6. 제출 전 필수 확인 두 가지

### (1) 모든 노트북을 처음부터 다시 실행

각 노트북마다 **Kernel → Restart Kernel and Run All Cells...** 로 끝까지 오류 없이 통과하는지 확인합니다.

> 셀을 위아래로 오가며 실행하면 채점자 환경에서 재현되지 않습니다.
> 위에서 아래로 한 번에 통과해야 합니다.

### (2) pytest 전수 통과

이 폴더에서:

```powershell
pytest -v
```

실패 0 이어야 합니다.

---

## 7. 제출물 만들기

- 파일명: `lv1_module3_이름.zip`
- 구성 순서: `notebooks/` → `src/` → `tests/` → `requirements.txt`
- `.venv/`, `__pycache__/`, `.pytest_cache/` 는 넣지 않습니다.

```powershell
Compress-Archive -Path notebooks, src, tests, requirements.txt -DestinationPath lv1_module3_홍길동.zip
```

---

## 8. 자주 걸리는 문제

| 증상 | 원인과 해결 |
|---|---|
| `NotImplementedError` | 아직 구현하지 않은 함수입니다. 해당 `src/*.py` 를 채우고 커널을 재시작하세요. |
| `ModuleNotFoundError: No module named 'src'` | 노트북을 `notebooks/` 안에서 열면 cwd 가 달라집니다. 첫 셀의 `sys.path.insert(0, str(ROOT))` 가 이를 처리하므로 **첫 셀부터** 실행하세요. |
| 함수를 고쳤는데 노트북 결과가 그대로 | 커널이 예전 모듈을 캐시하고 있습니다. 커널 재시작 또는 `%autoreload 2`. |
| `.\.venv\Scripts\Activate.ps1` 실행 거부 | `Set-ExecutionPolicy -Scope Process -ExecutionPolicy RemoteSigned` 후 재시도. |
| 그래프의 한글이 네모(□)로 보임 | 각 노트북 첫 셀이 `Malgun Gothic` 등을 자동으로 잡습니다. 폰트가 없으면 `plt.rcParams["font.family"]` 를 설치된 한글 폰트 이름으로 바꾸세요. |
| `ImportError: DLL load failed ... 애플리케이션 제어 정책에서 이 파일을 차단했습니다` | 사내 PC 의 WDAC/AppLocker 가 특정 휠의 DLL 을 막는 경우입니다. 해당 패키지를 **한 단계 낮은 버전**으로 설치하면 대개 해결됩니다 (예: `scipy==1.15.3`, `pyzmq==26.2.0`). |
| JupyterLab 커널이 계속 죽음 | 위와 같은 `pyzmq` DLL 차단이 원인일 수 있습니다. `python -c "import zmq"` 로 먼저 확인하세요. |
| 채점 기준과 수치가 다름 | 시드를 확인하세요. **`np.random.default_rng(42)`** 입니다. |
