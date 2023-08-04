import java.util.ArrayList;

public class blockSearch {

    public static void main(String[] args) {

        int arr[] = {8,1,6,24,28,32,29,45,60,95,64,74,99};
        Block b1 = new Block(20, 0, 2);
        Block b2 = new Block(50, 3, 7);
        Block b3 = new Block(100, 8, 12);
        ArrayList<Block> alb = new ArrayList<>();
        alb.add(b1);
        alb.add(b2);
        alb.add(b3);
        int target = 99;
        OUT:
        for(int i = 0; i<alb.size();i++)
        {
            if(target > alb.get(i).getMaxVal())
            {
                continue;
            }
            else{
                for(int j = alb.get(i).getLeftIndex(); j <= alb.get(i).getRightIndex(); j++)
                {
                    if(target == arr[j])
                    {
                        System.out.println("found");
                        break OUT;
                    }
                }
                System.out.println("no found");
                break;
            }
        }

    }




}

class Block {
    public Block(int maxVal, int leftIndex, int rightIndex) {
        this.maxVal = maxVal;
        this.leftIndex = leftIndex;
        this.rightIndex = rightIndex;
    }

    public int getMaxVal() {
        return maxVal;
    }

    public int getLeftIndex() {
        return leftIndex;
    }

    public int getRightIndex() {
        return rightIndex;
    }

    public void setMaxVal(int maxVal) {
        this.maxVal = maxVal;
    }

    public void setLeftIndex(int leftIndex) {
        this.leftIndex = leftIndex;
    }

    public void setRightIndex(int rightIndex) {
        this.rightIndex = rightIndex;
    }

    int maxVal;
    int leftIndex;
    int rightIndex;
}

Runtime r = Runtime.getRuntime();
        System.out.println(r.availableProcessors());
        System.out.println(r.getRuntime());
        //r.exit(0);
        //get max memory
        System.out.println(r.maxMemory() / 1024 / 1024/ 1024);

        System.out.println(r.totalMemory()/1024);
        try {
            r.exec("notepad");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
package cola.ice;

public class Person {
    Person(){

    }
    Person(String name, int age){
        this.age = age;
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void message(){
        System.out.println("person");
    }

    public void setAge(int age) {
        this.age = age;
    }

    String name;
    int age;
}

package cola.ice;

public class Student extends Person{
    public Student(){}
    Student(String name, int age){
        super(name, age);
    }
    public void study(){
        System.out.println("student is studying.");
    }
}


package cola.ice;

public class Teacher extends Person{
    Teacher(){}
    public Teacher(String name, int age)
    {
        super(name, age);
    }
    public void work()
    {
        System.out.println("teacher is teaching.");
    }
}


import cola.ice.Person;
import cola.ice.Student;

import java.util.*;
//封装  继承  多态，内部类
public class Main{
    public static void main(String args[])
    {
        StringBuilder sb = new StringBuilder();
        StringJoiner sj = new StringJoiner(",");
        sj.add("aaa").add("BBB").add("ccc");
        System.out.println(sj);
        System.out.println(sj.toString());
        Person p = new Student();
        p.message();
        Student c = (Student)p;
        c.study();

    }
}


import java.util.*;

public class Main{
    public static void main(String args[])
    {
        int v;
        int arr[] = {3,4,5,7,8,5,3};
        Arrays.sort(arr);
        System.out.println("Arr: "+Arrays.toString(arr));
        int arr2[] = Arrays.copyOf(arr, 4);
        System.out.println("Arr2: "+Arrays.toString(arr2));
        int arr3[] = Arrays.copyOfRange(arr, 5,6);
        System.out.println("Arr3: "+Arrays.toString(arr3));
        System.out.println(Arrays.equals(arr, arr2));
        int arr4[] = Arrays.copyOf(arr, arr.length);
        System.out.println(Arrays.equals(arr, arr4));
        int arr5[] = new int[6];
        Arrays.fill(arr5, 10);
        System.out.println("Arr5: "+Arrays.toString(arr5));
        System.arraycopy(arr, 1,arr5,3,2);
        System.out.println("Arr5: "+Arrays.toString(arr5));
        int arr6[][] = new int[3][];
        arr6[1] = arr;
        arr6[2] = arr2;
        arr6[0] = arr5;
        for(int i = 0; i < arr6.length;++i)
        {
            for(int j: arr6[i])
                System.out.print(j+" ");
            System.out.println();
        }
        for(int[] i : arr6)
        {
            for(int j : i)
                System.out.print(j+" ");
            System.out.println();
        }
    }
}

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
