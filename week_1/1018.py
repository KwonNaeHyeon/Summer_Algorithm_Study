N, M = map(int, input().split())  # 만들 매트릭스 행과 열 개수 입력
original = []
count = []

for _ in range(N):
    original.append(input())    # 사용자로부터 매트릭스를 입력받음

for a in range(N-7):        # 첫 줄 첫 칸 시작점 검사
    for b in range(M-7):
        index1 = 0
        index2 = 0
        for i in range(a, a+8):     # 짝수와 홀수를 이용하여 바뀐 체스판 count
            for j in range(b, b+8):
                if (i+j) % 2 == 0:
                    if original[i][j] != 'W':
                        index1 += 1
                    if original[i][j] != 'B':
                        index2 += 1
                else:
                    if original[i][j] != 'B':
                        index1 += 1
                    if original[i][j] != 'W':
                        index2 += 1
        count.append(min(index1, index2))       # 최소값을 구하기 위해 비교

print(min(count))       # 최소값 출력
