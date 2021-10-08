public class DoublyLinkedList {
	Node head;
	static class Node {
		int data;
		Node next;
		Node prev;
		
		Node(int val) {
			data = val;
			next = null;
			prev = null;
		}
	}
	public static DoublyLinkedList insert_node(DoublyLinkedList list, int val, int pos) {
		Node n = new Node(val);
		int k = 1;
		if(pos == 1) {
			n.next = list.head;
			if(list.head != null) 
				list.head.prev = n;
			list.head = n;
		}
		else {
			Node temp = list.head;
			while(temp != null && k < pos) {
				k++;
				temp = temp.next;
			}
			if(temp == null)
				System.out.println("Invalid Position!");
			else {
				Node p = temp.prev;
				n.prev = p;
				n.next = temp;
				p.next = n;
				if(temp != null)
					temp.prev = n;
			}
		}
		return list;
	}
	public static DoublyLinkedList delete_node(DoublyLinkedList list, int pos) {
		if(list.head == null) {
			System.out.println("Empty List");
			return null;
		}
		Node temp = list.head;
		int k = 1;
		if(pos == 1) {
			list.head = list.head.next;
			if(list.head != null)
				list.head.prev = null;
		}
		else {
			while(temp != null && k < pos) {
				k++;
				temp = temp.next;
			}
			if(temp == null)
				System.out.println("Invalid position");
			else {
				Node p = temp.prev;
				p.next = temp.next;
				if(temp.next != null)
					temp.next.prev = p;
			}
		}
		return list;
	}
	public static void disp(DoublyLinkedList list) {
		Node temp = list.head;
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DoublyLinkedList list = new DoublyLinkedList();
		list = insert_node(list, 1, 1);
		list = insert_node(list, 2, 1);
		list = insert_node(list, 3, 2);
		list = insert_node(list, 4, 3);
		list = insert_node(list, 5, 1);
		list = insert_node(list, 6, 2);
		list = insert_node(list, 7, 3);
		System.out.println();
		disp(list);
		list = delete_node(list, 3);
		System.out.println();
		disp(list);
	}
}