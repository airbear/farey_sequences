package main;

import java.util.ArrayList;



public class FareySeq {
	
	/*
	 * считает расстояния (?)
	 * в общем, какую-то хрень считает. 
	 * тащем-то не нужна, также как и следущая, ибо количество элементов в последовательности
	 * можно узнать тупо из размера эррэй листа, но пусть будет, мало ли что 
	 */
	public static double An(int order) {
		double S = 0;
		for (int i = 1; i <= order; i++)
			S+=fi(i);
		return S;
	}
	/*
	 * вспомогательная, считает фи энные(ф-ия эйлера)
	 */
 	public static double fi(int n) {
		//ищем простые числа, которые меньше n? и проверяем, являются ли делителем n?
		//или мб таки лучше искать делители и проверять, простые ли?
		//короче так. юзаем решето эратосфена, ищем все простые от 1 до n и потом проверяем
		ArrayList<Boolean> prime = new ArrayList<Boolean>();
		prime.add(false); prime.add(false);
		for(int i = 2; i <= n; i++)
			prime.add(true);
		for (int i=2; i<=n; ++i)
			if (prime.get(i))
				if (i * i <= n)
					for (int j=i*i; j<=n; j+=i)
						prime.set(j,false);
		//теперь ещё те выкинем, которые не делители
		for(int i = 0; i <= n; i++) {
			if(prime.get(i))
				if(n % i != 0)
					prime.set(i,false);
		}
		//получили что-то вроде массива нужных делителей, теперь считаем
		double f = 1;
		for(int i = 0; i <=n; i++)
			if(prime.get(i))
				f *= 1 - 1.0/i;
		f *= n;
		return f;
	}
 	
 	
 	
 	/*
 	 * строит последовательность фарея
 	 * order - порядок, до которого нужно построить
 	 * start - последовательность, с которой начать строить. мб и не надо
 	 * напока мне кажется, что так будет побыстрее на оче больших порядках
 	 */
	public static ArrayList<Farey> getFareySeq(ArrayList<Farey> start, int order) {
		Farey tmp1,tmp2;
		ArrayList<Farey> current = new ArrayList<Farey>(start);
		//построение до указанного в order порядка:
		//надо узнать, какой порядок был у переданной последовательности старт:
		int order_start = start.get(start.size()-1).down; //ибо там 1/n
		for (int i = order_start +1; i <= order; i++) {
			if(current.isEmpty()) System.out.println("wtf bro current is empty");
			ArrayList<Farey> last = new ArrayList<Farey>(current);
			current.clear();
			//отдельно берем первую дробь из последовательности, сразу удаляем из списка и кладем в current
			tmp1 = last.get(0); last.remove(0);
			current.add(tmp1);
			while (! last.isEmpty()) {
				tmp1 = last.get(0); last.remove(0);
				if((tmp1.down + current.get(current.size()-1).down) <= i) {
					//впихиваем между ними медианту:
					tmp2 = current.get(current.size()-1);
					Farey tmp3 = new Farey(tmp1.up + tmp2.up, tmp1.down + tmp2.down);
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
	
	
	static double dkn(Farey q, int k, double A) {
		return (q.up * A - k*q.down)/A/q.down;
	}
	
	static double K1(ArrayList<Farey> F) {
		double sum = 0;
		for(int i = 0; i < F.size(); i++) {
			int k = F.size()-1-i;
			sum += dkn(F.get(k),i+1,F.size()) * dkn(F.get(k),i+1,F.size());
		}
		return sum;
	}
	
	static double K2(ArrayList<Farey> F) {
		double sum = 0;
		for(int i = 0; i < F.size(); i++) {
			int k = F.size()-1-i;
			sum += Math.abs(dkn(F.get(k),i+1,F.size()));
		}
		return sum;
	}
}

