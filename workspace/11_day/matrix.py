import numpy as np

A = np.array([[1,2], [3,4]])

print(A)


# 행렬 A, B 정의
A = np.array([[1, 2], [3, 4]])
B = np.array([[5, 6], [7, 8]])

# 1. 행렬 덧셈과 뺄셈 (같은 위치의 원소끼리 연산)
print("덧셈:\n", A + B)
print("뺄셈:\n", A - B)

# 2. 요소별(Element-wise) 곱셈과 나눗셈 (*, /)
print("요소별 곱셈:\n", A * B)
print("요소별 나눗셈:\n", A / B)

# 3. 수학적 행렬 곱셈 (@ 또는 np.dot)
print("행렬 곱 (@):\n", A @ B)
print("행렬 곱 (dot):\n", np.dot(A, B))



A = np.array([[1, 2], [3, 4]])

# 전치 행렬 (A.T 또는 np.transpose)
print("전치 행렬:\n", A.T)

# 역행렬 (np.linalg.inv)
print("역행렬:\n", np.linalg.inv(A))