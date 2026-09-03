class Sensor:
    """모든 센서의 공통 기반."""
    def __init__(self, name: str, port: str):
        self.name = name             # 인스턴스 속성
        self.port = port
        self.is_connected = False

    def connect(self) -> None:
        self.is_connected = True

    def read(self):
        raise NotImplementedError    # 자식이 반드시 구현해야 함

class Lidar(Sensor):                 # 상속
    def read(self) -> list[float]:   # 오버라이드
        return [0.8, 0.82, 0.85]     # (실제로는 장치에서 읽음)

class Imu(Sensor):
    def read(self) -> dict[str, float]:
        return {"pitch": 2.1, "roll": -0.3}

# 다형성 — 타입을 몰라도 동일하게 다룬다
sensors: list[Sensor] = [Lidar("front", "/dev/lidar"), Imu("body", "/dev/imu")]
for s in sensors:
    s.connect()
    print(s.name, s.read())          # 같은 호출, 다른 동작


# # ==============================
# # Python .py 파일 실행
# # ==============================

# # 기본 실행
# python main.py

# # python3을 사용하는 환경
# python3 main.py


# # ==============================
# # 가상환경에서 실행
# # ==============================

# # Linux / macOS
# source venv/bin/activate
# python main.py

# # Windows
# venv\Scripts\activate
# python main.py


# # ==============================
# # PyInstaller로 빌드
# # ==============================

# # .py 파일을 실행 파일로 빌드
# pyinstaller --onefile main.py


# # ==============================
# # 빌드된 실행 파일 실행
# # ==============================

# # Linux / macOS
# ./dist/main

# # Windows
# .\dist\main.exe