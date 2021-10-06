//import java.io.*;
//import java.util.Scanner;
public class Linked_List {
	Node head;
	static class Node {
		int data;
		Node next;
		
		Node(int val) {
			data = val;
			next = null;
		}
	}
	public static Linked_List insert(Linked_List list, int val, int pos) {
		Node temp = new Node(val);
		temp.next = null;
		Node curr = list.head;
		Node p = null;
		if(list.head == null)
			list.head = temp;
		else if(pos == 1) {
			temp.next = list.head;
			list.head = temp;
		}
		else {
			int k = 1;
			while(curr != null && k < pos) {
				k++;
				p = curr;
				curr = curr.next;
			}
			if(curr == null)
				System.out.println("No node found!");
			else {
				p.next = temp;
				temp.next = curr;
			}
		}
		return list;
	}
	public static Linked_List deletion(Linked_List list, int pos) {
		int k = 1;
		Node temp = list.head;
		if(list.head == null)
			System.out.println("Empty List!");
		else if(pos == 1) 
			list.head = list.head.next;
		else {
			Node p = null;
			while(temp != null && k < pos) {
				k++;
				p = temp;
				temp = temp.next;
			}
			if(temp == null)
				System.out.println("Position not found!");
			else 
				p.next = temp.next;
		}
		return list;
	}
	public static Node reversing(Linked_List list) {
		Node curr = list.head;
		Node p = null;
		while(curr != null) {
			Node n = curr.next;
			curr.next = p;
			p = curr;
			curr = n;
		}
		return p;
	}
	public static void print_ll(Linked_List list) {
		Node temp = list.head;
		while(temp != null) {
			System.out.print(temp.data+" ");
			temp = temp.next;
		}
		System.out.println();
	}
	public static void print_n(Node head) {
		while(head != null) {
			System.out.print(head.data + " ");
			head = head.next;
		}
		System.out.println();
	}
	public static void main(String []args) {
		Linked_List list = new Linked_List();
		//Scanner sc = new Scanner(System.in);
		//System.out.print("Enter the number of elements to be entered : ");
		//int n = sc.nextInt();
		/*for(int i = 1; i <= n; i++) {
			System.out.print("Enter the element : ");
			int ele = sc.nextInt();
			System.out.print("Enter the position : ");
			int pos = sc.nextInt();
			list = insert(list, ele, pos);
		}
		sc.close();*/
		list = insert(list, 1, 1);
		list = insert(list, 2, 1);
		list = insert(list, 4, 2);
		list = insert(list, 5, 1);
		list = insert(list, 3, 3);
		list = insert(list, 7, 4);
		list = insert(list, 6, 6);
		System.out.println();
		print_ll(list);
		
		list = deletion(list, 2);
		System.out.println();
		print_ll(list);
		Node r = reversing(list);
		System.out.println("Reversed List - ");
		print_n(r);
	}
}