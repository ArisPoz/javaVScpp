import java.util.concurrent.TimeUnit;
import java.util.Random;

class A2 {
    public int data1;
    public int data2;
};

public class A {
    public static void createGarbage(int size) {
        for(int j = 0; j < size; j++) {
            A2 a = new A2();
            a.data1 = j;
            a.data2 = j*2;
            a = null;
        }
    }

    public static void allocate(int in) {
        int size = in;
        A2 a = null;
        A2 ar[] = new A2[size];
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            createGarbage(100);
            a = new A2();
            a.data1 = i;
            a.data2 = i*2;
            ar[i] = a;
        }

        Random rgen = new Random();		
		for (int i=0; i<size; i++) {
            int pos = rgen.nextInt(size);
            A2 temp = ar[i];
            ar[i] = ar[pos];
            ar[pos] = temp;
		}

        for (int i = 0; i < size; i++) {
            sum += ar[i].data2 + ar[i].data1;
            ar[i] = null;
        }

        System.out.println("Total: " + sum);
        System.out.println("Phase completion");
    }

    public static void main(String args[]) {
        double start = System.currentTimeMillis();
        allocate(Integer.parseInt(args[0]));
        System.out.println("Duration: " + 
        ((System.currentTimeMillis() - start) / 1000) + "s");
    }
}