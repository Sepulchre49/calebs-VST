import cmath
import math
import matplotlib.pyplot as pyplt
def freqGenerator(step):
    i = 0
    while i <= cmath.pi:
        i += cmath.pi / step
        yield i

def H(freq, coeffs):
    return coeffs[0] + cmath.rect(coeffs[1], -1*freq)

freq = []
gain = []
phase = []
for i in freqGenerator(32):
    output = H(i, [0.1,0.1])
    freq.append(i)
    gain.append(cmath.polar(output)[0])
    phase.append(cmath.polar(output)[1])

fig, ax = pyplt.subplots(2)
ax[0].scatter(freq, gain)
ax[1].scatter(freq, phase)

pyplt.show()
