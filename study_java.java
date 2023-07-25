import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int arr[];
        arr = new int[3];
        arr[1] = 5;
        int arr2[] = new int[]{1,3,5};
        int arr3[] = {1,2,3,4,5,6};
        System.out.println("print x");
        System.out.println(Arrays.binarySearch(arr3, -2));
        for(int i: arr3)
        {
            System.out.println(i);
        }
        System.out.println(arr2);
        for(int i = 0; i < 3; i++)
        {
            //System.out.println(arr[i]);
            System.out.println(arr2[i]);
        }
    }
}

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        // Press Opt+Enter with your caret at the highlighted text to see how
        // IntelliJ IDEA suggests fixing it.
        System.out.println("Hello and welcome!");

        // Press Ctrl+R or click the green arrow button in the gutter to run the code.
        //标签
	outer:
        for (int i = 1; i <= 100; i++) {

            // Press Ctrl+D to start debugging your code. We have set one breakpoint
            // for you, but you can always add more by pressing Cmd+F8.
            System.out.println("i = " + i);
            while(i <= 5)
            {
                i += 1;
                System.out.println("inner: i = "+i);
                if(i == 5)
                    break outer;//直接break标签层的循环
            }
            System.out.println("i = "+i);
        }
    }
}

import java.util.*; // *代表所有
import java.util.Scanner; //在java.util 里面将scanner拿过来用
public class test3{
	public static void main(String[] args){
		char a = 'A';
		char c = '中';
		System.out.print(a+1);
		boolean f = false;
		System.out.print(f);
		//被final修饰的词不可变:字符常量
		final double PI = 3.14;
		
		//创建一个扫描器
		Scanner sc = new Scanner(System.in);
		//让扫描器录入一个int类型的数据
		System.out.print("Please enter a INT>: ");
		int r = sc.nextInt();
		System.out.print("Please enter a string>: ");
		String str = sc.next();
		System.out.print("Please enter a char>: ");
		String str2 = sc.next();
		char ch = str2.charAt(0);
		System.out.println(r+str+ch);
		System.out.println(12/5);
	}
}

public class test2{
	public static void main(String[] args){
		int age;
		age = 10;
		System.out.println(age);
		int num1 = 12;//
		int num2 = 012;//
		int num3 = 0x12;//hex
		int num4 = 0b10;//binary
		System.out.println(num1);
		System.out.println(num2);
		System.out.println(num3);
		System.out.println(num4);
		//default right value is int, so 123456789120 does not exist
		long num5 = 123456789120L;//have to put L to declare that is a long
		System.out.println("num5 = "+num5);
		
	}
}
public class test{
	public static void main(String[] args){
		System.out.print("name:");
		System.out.println("Cola");
		System.out.print("age:");
		System.out.println("25");
		System.out.println();//print empty line
		System.out.print("12345678123456781234567812345678\n");
		// \t 空出一个制表符也就是八个位置
		System.out.println("12\t1234");
		System.out.print("12345678123456781234567812345678\n");
		System.out.println("1234\t1234");
		System.out.print("12345678123456781234567812345678\n");
		System.out.println("123456\t1234");
		System.out.print("12345678123456781234567812345678\n");
		System.out.println("1234567\t1234");
		System.out.print("12345678123456781234567812345678\n");
		System.out.println("12345678\t1234");
	}
}
