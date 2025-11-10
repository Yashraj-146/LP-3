# 1
import matplotlib.pyplot as plt

# 2
# Function: y = (x + 3)^2
def f(x):
    return (x + 3)**2

# Derivative: dy/dx = 2(x + 3)
def df(x):
    return 2 * (x + 3)

# 3
def gradient_descent(df, start_x, learning_rate=0.1, iterations=50):
    x = start_x
    x_list, y_list = [x], [f(x)]

    for i in range(iterations):
        grad = df(x)
        x = x - learning_rate * grad
        x_list.append(x)
        y_list.append(f(x))

        print(f"Iteration {i+1}: x = {x:.4f}, f(x) = {f(x):.4f}")

    print(f"\nLocal minima occurs at x = {x:.4f}")
    return x_list, y_list

# 4
# Starting from x = 2
x_points, y_points = gradient_descent(df, start_x=2, learning_rate=0.1, iterations=50)

# 5
plt.figure(figsize=(8,5))
plt.plot(x_points, y_points, 'bo-', label='Gradient Descent Path')
plt.title('Gradient Descent Convergence')
plt.xlabel('x values')
plt.ylabel('f(x) values')
plt.grid(True)
plt.legend()
plt.show()
