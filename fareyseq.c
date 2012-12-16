#include <stdio.h>

static double K1 = 0;
static double K2 = 0;

struct farey {
	unsigned int up;
	unsigned int down;
};

/* вспомогательная, считает фи энные(ф-ия эйлера) */
unsigned long long int fi(int n)
{
	//короче так. юзаем решето эратосфена, ищем все простые от 1 до n и потом проверяем
	unsigned int prime[n];
	unsigned long int i;
	unsigned long int j;
	prime[0] = 0;
	prime[1] = 0;
	for (i = 2; i <= n; i++) {
		prime[i] = 1;
	}

	for (i = 2; i <= n; ++i)
		if (prime[i])
			if (i * i <= n)
				for (j = i * i; j <= n; j += i) {
					prime[j] = 0;
				}
	//теперь ещё те выкинем, которые не делители
	for (i = 0; i <= n; i++) {
		if (prime[i])
			if (n % i != 0) {
				prime[i] = 0;
			}
	}

	//получили что-то вроде массива нужных делителей, теперь считаем
	double f = 1;
	for (i = 0; i <= n; i++)
		if (prime[i])
			f *= 1.0 - 1.0 / i;
	f *= n;
	return (long long int)f;
}

/* Вспомогательная для K1 / K2 */
double dkn(farey *q, int k, unsigned long long int A)
{
	return ((q->up * A - k * q->down) / (A * 1.0)) / q->down;
}

/*
 * считает расстояния (?)
 * в общем, какую-то хрень считает. 
 * тащем-то не нужна, также как и следущая, ибо количество элементов в последовательности
 * можно узнать тупо из размера эррэй листа, но пусть будет, мало ли что 
 */
unsigned long long int elem_count(int order)
{
	unsigned long long int s = 0;
	unsigned int i;
	for (i = 1; i <= order; i++)
		s += fi(i);
	return s;
}



void magic(int n)
{
	int i,j;
	struct farey current[1];
	current[0].up = 1;
	current[0].down = 1;
	for (i = 2; i < n; i++) {
		struct farey last[i-1];
		for (j = 0; j < i - 1; j++) 
			last[j] = current[j];
		
			
	}

	return;
}



/*
 * строит последовательность фарея
 * order - порядок, до которого нужно построить
 * start - последовательность, с которой начать строить. мб и не надо
 * напока мне кажется, что так будет побыстрее на оче больших порядках
 */

/* 
 * 1. Берем массив current (то от чего отталкиваемся, т.е. start)
 * 2. Узнаем порядок переданной последовательности (order / 10)
 * 3. В цикле до указанного переданного порядка (order)
 * 4. Меняем местами last и current 
 */



#if 0
public static ArrayList < Farey > getFareySeq(ArrayList < Farey > start,
					      int order)
{
	Farey tmp1, tmp2;
	ArrayList < Farey > current = new ArrayList < Farey > (start);
	//построение до указанного в order порядка:
	//надо узнать, какой порядок был у переданной последовательности старт:
	int order_start = start.get(start.size() - 1).down;	//ибо там 1/n
	for (int i = order_start + 1; i <= order; i++) {
		ArrayList < Farey > last = new ArrayList < Farey > (current);
		current.clear();
		//отдельно берем первую дробь из последовательности, сразу удаляем из списка и кладем в current
		tmp1 = last.get(0);
		last.remove(0);
		current.add(tmp1);
		while (!last.isEmpty()) {
			tmp1 = last.get(0);
			last.remove(0);
			if ((tmp1.down +
			     current.get(current.size() - 1).down) <= i) {
				//впихиваем между ними медианту:
				tmp2 = current.get(current.size() - 1);
				Farey tmp3 = new Farey(tmp1.up + tmp2.up,
						       tmp1.down + tmp2.down);
				current.add(tmp3);
				current.add(tmp1);
			} else {
				//просто кидаем новый в current
				current.add(tmp1);
			}
		}
		current.add(new Farey(1, i));
	}

	/*
	 * распечатка построенной последовательности. для проверки
	 for(int i=0; i < current.size(); i++) {
	 System.out.println(current.get(i).up + "/" + current.get(i).down);
	 }
	 */
	return current;
}

/*
 * some exp shit
 * 
 */




#endif

#if 0
static double K2(ArrayList < Farey > F)
{
	double sum = 0;
	for (int i = 0; i < F.size(); i++) {
		int k = F.size() - 1 - i;
		sum += Math.abs(dkn(F.get(k), i + 1, F.size()));
	}
	return sum;
}

static double K1(ArrayList < Farey > F)
{
	double sum = 0;
	for (int i = 0; i < F.size(); i++) {
		int k = F.size() - 1 - i;
		sum +=
		    dkn(F.get(k), i + 1, F.size()) * dkn(F.get(k), i + 1,
							 F.size());
	}
	return sum;
}
#endif
