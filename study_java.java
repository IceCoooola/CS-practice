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
