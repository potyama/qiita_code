import numpy as np


class GetPi:

    #比較用
    def numpy_pi(self):
        print("Pi: {}".format(np.pi))
    #逆正接関数
    def arctan(self):
        print("Arctan_Pi: {}".format(4 * np.arctan(1)))

    #ライプニッツの公式
    def leibniz_formula(self, _n):
        x = np.arange(1, _n + 1)
        pi = np.sqrt(6 * np.sum(1 / x ** 2))
        print("Leibniz_Pi: {}".format(pi))

    # バーゼル級数
    def basel_series(self, _n):
        x = np.arange(1, _n + 1)
        a = 1 / (2 * x - 1)
        b = (-1) ** (x - 1)
        pi = 4 * np.dot(a, b)
        print("Basel_Pi: {}".format(pi))


    # マチンの公式
    def machin_like_formula(self, _n):
        X = 0.0
        for n in range(3*_n+2):
            a = ((-1)**n)
            b = 2*n + 1
            X += a/b * (1/5)**(2*n+1)

        Y = 0.0
        for n in range(_n):
            a = ((-1)**n)
            b = 2*n + 1
            Y += a/b * (1/239)**(2*n+1)
        print("Machin_Pi: {}".format((16*X) - (4*Y)))

    #ラマヌジャンの公式
    def ramanujan_series(self, _n):
        sum = 0.0
        for n in range(_n):
            a = np.math.factorial(4 * n) * (1103 + 26390 * n)
            b = (396**n * np.math.factorial(n))**4
            sum += a/b

        pi = (2*np.sqrt(2))/(99**2) * sum
        print("Ramanujan_Pi: {}".format((1/pi)))
    #モンテカルロ法
    def montecarlo_method(self, _n):
        alpha = _n
        beta = 0
        ran_x = np.random.rand(alpha)
        ran_y = np.random.rand(alpha)
        ran_point = np.hypot(ran_x, ran_y)

        for i in ran_point:
            if i <= 1:
                beta += 1

        pi = 4*beta/alpha
        print("MonteCalro_Pi: {}".format(pi))

n = 5
pi = GetPi()
pi.numpy_pi()
pi.arctan()
pi.leibniz_formula(n)
pi.basel_series(n)
pi.machin_like_formula(n)
pi.ramanujan_series(5)
pi.montecarlo_method(n)