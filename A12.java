/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypackage;
import java.util.*;

/**
 *
 * @author Pujashree
 */
abstract class MyStack
{
    public final void pushTemplateMethod()
    {
        show();
        push();
        display();
    }
abstract protected void push();
abstract protected void display();
protected void show()
{
    System.out.println("Stack implementation");
}

public final void popTemplateMethod()
{
        show();
        pop();
        display();
}
abstract protected void pop();
}

class IntStack extends MyStack
{
    Stack <Integer> s= new Stack<Integer>();
    protected void push()
    {
    	System.out.println("Enter the number you want to push:");
    	Scanner s=new Scanner(System.in);
    	int x=s.nextInt();
    	try
    	{
    		s.push(x);	
    	}
    	catch(Exception e)
    	{
    		System.out.println("Stack Overflow!");
    	}
        
    }

    protected void pop()
    {
    	try
    	{
			System.out.println("Popped element:"+s.pop());
    	}
    	catch(Exception e)
    	{
    		System.out.println("Stack Underflow!");
    	}
    }
protected void display()
{
    while(!s.isEmpty())
    {
        System.out.println(s.pop());
    }
}
}
public class A12 
{
     public static void main(String[] args)
     {
         IntStack obj=new IntStack();
         int ch;
         do
         {
         System.out.println("\n1.Push \n2.Pop \n3.Exit \nEnter your choice:");
         Scanner s=new Scanner(System.in);
         ch=s.nextInt();
         switch(ch)
         {
        	 case 1:
        	 	obj.pushTemplateMethod();
        	 	break;

        	 case 2:
         	 	obj.popTemplateMethod();
         	 	break;
     	 }
     	}while(ch!=3);
     }
}
