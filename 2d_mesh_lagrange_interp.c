/*
* 2d mesh using Lagrange interpolation.
* esasharahi@gmail.com  Bardal‫®‬
*/

double *descrete_interval (double a, double b, double step)
{
	double pre_len = (b - a) / step;
	int len = (int) ceil(pre_len);
	double *interval = malloc((len + 1) * sizeof(double*));
	interval[0] = a;
	for (int i = 1; i < len; i++)
	{
		interval[i] = interval[i - 1] + step;
	}
	interval[len] = b;
	return interval;
}

double l_2d (int n, double ar[n], double ar_xi[n], double ar_eta[n], double xi, double eta)
{
	double result = 0;
	for (int index = 0; index < n; index++)
	{
		double p = 1;
		for (int i = 0; i < n ; i++)
		{
			if (!(ar_eta[i] != ar_eta[index] || i == index))
			{
				p *= (xi - ar_xi[i]) / (ar_xi[index] - ar_xi[i]);
			}
			if (!(ar_xi[i] != ar_xi[index] || i == index))
			{
				p *= (eta - ar_eta[i]) / (ar_eta[index] - ar_eta[i]);
			}
		}
		p *= ar[index];
		result += p;
	}
	return result;
}
