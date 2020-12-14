class B2 {
    public int data1;
    public int data2;
};

public class B {

    public static void createGarbage(int size) {
        for(int j = 0; j < size; j++) {
            B2 b = new B2();
            b.data1 = j;
            b.data2 = j*2;
            b = null;
        }
    }

    public static void allocate(int in) {
        int size = in;
        B2 ar[] = new B2[size];

        createGarbage(size);
        for (int i = 0; i < size; i++) {
            B2 b = new B2();
            b.data1 = i;
            b.data2 = i*2;
            ar[i] = b;
        }

        createGarbage(size);
        for (int i = 0; i < size; i++) {
            if(10 % (i+1) != 2) {
                ar[i] = null;
            }
        }

        for (int i = 0; i < size; i++) {
            B2 b = new B2();
            b.data1 = i;
            b.data2 = i*2;
            ar[i] = b;
        }

        createGarbage(size);
        for (int i = 0; i < size; i++) {
            ar[i] = null;
        }

        System.out.println("Phase completed");
    }

    public static void main(String args[]) {
        double start = System.currentTimeMillis();
        allocate(Integer.parseInt(args[0]));
        System.out.println("Duration: " + 
        ((System.currentTimeMillis() - start) / 1000) + "s");
    }
}
