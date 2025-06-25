Q1.Better way to pick the bisection range ?

Instead of manually guessing a range, we can start with an initial guess "x0" and expand the range in both directions (x0 ± step * 2^k) until a sign change is detected.

This approach is known as auto-bracketing dynamic range selection , and it often leads to:

- A smaller interval containing the root
- Faster convergence (fewer bisection iterations)
- More reliable when the initial root is unknown

This improves both accuracy and efficiency over the traditional method.




Q2.Compare performance with number of iterations.
We compare:

-> Traditional Bisection Method (given range [a, b])
-> Better Approach: Automatically detects a valid range [a, b] where f(a)*f(b) < 0

🔍 Theoretical Comparison

Criteria	        Traditional Method	       Better Approach (Auto-Bracket)
Interval used	    Fixed: [1.0, 2.0]	       Auto-detected near guess x₀ = 1.5
Interval size	      1.0	                        ~0.05
Iterations needed	  19	                             15
Accuracy	         Same (ε = 1e-6)	            Same (ε = 1e-6)
Performance	         Baseline            	    ~21% fewer iterations