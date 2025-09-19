import time

N = 1000000000  # 1 billion iterations

# --- For loop ---
start = time.perf_counter()
sum_for = 0
for i in range(N):
    sum_for += i
end = time.perf_counter()
print(f"For loop:     {end - start:.3f} seconds (sum={sum_for})")

# --- While loop ---
start = time.perf_counter()
sum_while = 0
j = 0
while j < N:
    sum_while += j
    j += 1
end = time.perf_counter()
print(f"While loop:   {end - start:.3f} seconds (sum={sum_while})")

# --- Do-while loop simulation ---
start = time.perf_counter()
sum_do = 0
k = 0
if N > 0:
    while True:
        sum_do += k
        k += 1
        if not (k < N):
            break
end = time.perf_counter()
print(f"Do-while loop: {end - start:.3f} seconds (sum={sum_do})")
