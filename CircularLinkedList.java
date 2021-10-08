
public class CircularLinkedList {
	Node head;
	static class Node {
		int data;
		Node next;
		Node (int val) {
			data = val;
			next = null;
		}
	}
	public static CircularLinkedList insertion(CircularLinkedList list, int val, int pos) {
		Node n = new Node(val);
		Node curr = list.head, p = null;
		n.next = n;
		if(list.head == null) {
			list.head = n;
			return list;
		}
		do {
			p = curr;
			curr = curr.next;
		}while(curr != list.head);
		
		if(pos == 1) {
			n.next = list.head;
			p.next = n;
			list.head = n;
		}
		else {
			int k = 1;
			do {
				k++;
				p = curr;
				curr = curr.next;
			}while(curr != list.head && k < pos);
			if(curr == list.head)
				System.out.println("Position not found!");
			else {
				p.next = n;
				n.next = curr;
			}
		}
		return list;
	}
	public static CircularLinkedList deletion(CircularLinkedList list, int pos) {
		Node temp = list.head, p = null;
		if(list.head == null) {
			System.out.println("Empty List!");
			return null;
		}
		do {
			p = temp;
			temp = temp.next;
		}while(temp != list.head);
		if(pos == 1) {
			list.head = temp.next;
			p.next = list.head;
		}
		else {
			int k = 1;
			do {
				k++;
				p = temp;
				temp = temp.next;
			}while(temp != list.head && k < pos);
			if(temp == list.head)
				System.out.println("Invalid position entered.");
			else {
				p.next = temp.next;
			}
		}
		return list;
	}
	public static void disp(CircularLinkedList list) {
		Node temp = list.head;
		do {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}while(temp != list.head);
		System.out.println();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CircularLinkedList list = new CircularLinkedList();
		list.head = null;
		list = insertion(list, 2, 1);
		list = insertion(list, 1, 1);
		list = insertion(list, 3, 1);
		list = insertion(list, 4, 2);
		list = insertion(list, 5, 3);
		list = insertion(list, 6, 2);
		list = insertion(list, 7, 4);
		disp(list);
		list = deletion(list, 7);
		list = deletion(list, 1);
		disp(list);
	}
}
