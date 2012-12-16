package main;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class AllAction {
	public static final int order = 1000;        //под порядок последовательности
	public static final double eps = 0.1;        //собственно, понятно, под что 
	public static ArrayList<Farey> last;         //под "предыдущую" последовательность
	public static ArrayList<Farey> current;      //под нужную последовательность
	
	public static void main(String[] args) throws IOException {
	/*	current = new ArrayList<Farey>();
		BufferedWriter out = new BufferedWriter(new FileWriter("/home/aki/mm.csv"));
		
		for (double e = 0.1; e>=eps; e/=10) {
			last = new ArrayList<Farey>();
			Farey tmp = new Farey(1,1);
			last.add(tmp);
			
			for(int n = 10; n <= order; n*=10) {
				current.clear();
				current = new ArrayList<Farey>(FareySeq.getFareySeq(last, n));
				double k1 = FareySeq.K1(current);
				k1 /= Math.pow(n, -1+e);
				//System.out.print(k1+";");
				//выходной файл:
			    try {
					out.write(k1 + ";");
				} catch (IOException err) {
					System.out.println(err.getMessage());
				}
				last.clear();
				last = new ArrayList<Farey>(current);
			}
			//System.out.println("^^");
			try {
				out.write("\n");
			} catch (IOException err) {
			}
		}
		out.close();
		System.out.println("^^");*/
		System.out.println(FareySeq.An(10000));
	}
}