#include <iostream>
#include <queue>
#include <array>

constexpr int MAX = (1e+6) + 2;

std::array<int, MAX> TOMATOES{};

struct Vector
{
	int m, n, o, p, q, r, s, t, u, v, w;
	int aged = 0;

	bool OOBCheck(Vector max_vector) const
	{
		return m < 0 || n < 0 || o < 0 || p < 0 || q < 0 ||
			r < 0 || s < 0 || t < 0 || u < 0 || v < 0 || w < 0 ||
			m >= max_vector.m || n >= max_vector.n || o >= max_vector.o || p >= max_vector.p || q >= max_vector.q
			|| r >= max_vector.r || s >= max_vector.s || t >= max_vector.t || u >= max_vector.u || v >= max_vector.v || w >= max_vector.w;
	}

	Vector operator +(const Vector& other) const
	{
		return {
			m + other.m,
			n + other.n,
			o + other.o,
			p + other.p,
			q + other.q,
			r + other.r,
			s + other.s,
			t + other.t,
			u + other.u,
			v + other.v,
			w + other.w,
			aged};
	}
};

int dirM[22] = {1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirN[22] = {0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirO[22] = {0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirP[22] = {0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirQ[22] = {0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirR[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirS[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0};
int dirT[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0};
int dirU[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0};
int dirV[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0};
int dirW[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};

int* access(Vector vec, const Vector& max_vector)
{
	int total = vec.m +
		vec.n * max_vector.m +
		vec.o * max_vector.m * max_vector.n +
		vec.p * max_vector.m * max_vector.n * max_vector.o +
		vec.q * max_vector.m * max_vector.n * max_vector.o * max_vector.p +
		vec.r * max_vector.m * max_vector.n * max_vector.o * max_vector.p * max_vector.q +
		vec.s * max_vector.m * max_vector.n * max_vector.o * max_vector.p * max_vector.q * max_vector.r +
		vec.t * max_vector.m * max_vector.n * max_vector.o * max_vector.p * max_vector.q * max_vector.r * max_vector.s +
		vec.u * max_vector.m * max_vector.n * max_vector.o * max_vector.p * max_vector.q * max_vector.r * max_vector.s * max_vector.t +
		vec.v * max_vector.m * max_vector.n * max_vector.o * max_vector.p * max_vector.q * max_vector.r * max_vector.s * max_vector.t * max_vector.u +
		vec.w * max_vector.m * max_vector.n * max_vector.o * max_vector.p * max_vector.q * max_vector.r * max_vector.s * max_vector.t * max_vector.u * max_vector.v;
	return &TOMATOES.at(total);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::queue<Vector> QUEUE;

	int m, n, o, p, q, r, s, t, u, v, w;
	std::cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
	
	Vector max_vector{m, n, o, p, q, r, s, t, u, v, w, 0};

	for (int a = 0; a < w; ++a)
	{
		for (int b = 0; b < v; ++b)
		{
			for (int c = 0; c < u; ++c)
			{
				for (int d = 0; d < t; ++d)
				{
					for (int e = 0; e < s; ++e)
					{
						for (int f = 0; f < r; ++f)
						{
							for (int g = 0; g < q; ++g)
							{
								for (int h = 0; h < p; ++h)
								{
									for (int i = 0; i < o; ++i)
									{
										for (int j = 0; j < n; ++j)
										{
											for (int k = 0; k < m; ++k)
											{
												int* pos = access({k, j, i, h, g, f, e, d, c, b, a}, max_vector);
												std::cin >> *pos;
												if (*pos == 1)
												{
													QUEUE.push({k, j, i, h, g, f, e, d, c, b, a, 0});
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int DAYS = 0;
	int AGEDCOUNT = 0;

	while(!QUEUE.empty())
	{
		Vector coord = QUEUE.front();
		QUEUE.pop();
		AGEDCOUNT++;
		DAYS = coord.aged;

		for(int i = 0; i < 22; ++i)
		{
			Vector new_offset{dirM[i],dirN[i],dirO[i],	dirP[i],	dirQ[i],	dirR[i],	dirS[i],	dirT[i],	dirU[i],	dirV[i], dirW[i]};
			Vector NEXT_COORD = coord + new_offset;

			if(NEXT_COORD.OOBCheck(max_vector))
			{
				continue;
			}

			int* state = access(NEXT_COORD, max_vector);

			if(*state == 0)
			{
				*state = 1;
				NEXT_COORD.aged = coord.aged + 1;
				QUEUE.push(NEXT_COORD);
			}
		}
	}

	int TOTAL = m * n * o * p * q * r * s * t * u * v * w;
	for(int i = 0; i < TOTAL; ++i)
	{
		if(TOMATOES[i] == 0)
		{
			std::cout << -1;
			return 0;
		}
	}

	std::cout << DAYS;
}