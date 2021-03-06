#include<iostream>

using namespace std;

class Node {
public:
	char data;
	Node* pre=nullptr;
	Node* next=nullptr;
};//노드를 만들어 진행 가장 처음은 blank노드(글자 삽입:ptr->next위치에 새 노드 삽입, 글자 삭제: ptr삭제 후 ptr=ptr->pre하기 위해 가장 처음 blank노드 생성 그래야 글자 삽입과 삭제를 진행 가능)
//< > - 를 blank일 때 아닐때 그리고 앞뒤 노드 존재여부를 바탕으로 분기 진행 마지막엔 가장 처음인 blank로 ptr이동 후 순서대로 출력
int main(void) {
	int test;
	cin >> test;
	for (int T = 0; T < test+1; T++) {
		char a;
		Node blank;
		Node* ptr = &blank;
		while (1) {
			scanf("%c",&a);
			if (a == '\n')
				break;
			if (ptr == &blank) {
				if (a == '-' || a=='<') {
					continue;
				}
				else if (a == '>') {
					if (ptr->next == nullptr)
						continue;
					else
					{
						ptr = ptr->next;
					}
				}
				else {
					if (ptr->next == nullptr) {
						Node* new_node=new Node();	new_node->data = a;	new_node->pre = &blank;
						ptr = new_node;
						blank.next = new_node;
					}
					else {
						Node* new_node = new Node();	new_node->data = a;
						new_node->next = ptr->next;	new_node->pre = &blank;
						new_node->next->pre = new_node;
						blank.next = new_node;
						ptr = new_node;
					}
				}
			}
			else {
				if (a == '-') {
					if (ptr->pre == nullptr) {
						continue;
					}
					else {
						ptr = ptr->pre;
						Node* delete_node = ptr->next;
						ptr->next = delete_node->next;
						if(delete_node->next!=nullptr)
							delete_node->next->pre = ptr;
						free(delete_node);
					}
				}
				else if (a == '>')
				{
					if (ptr->next == nullptr) {
						continue;
					}
					else {
						ptr = ptr->next;
					}
				}
				else if (a == '<')
				{
					if (ptr->pre == nullptr) {
						continue;
					}
					else {
						ptr = ptr->pre;
					}
				}
				else {
					Node* new_node = new Node();	new_node->data = a;	new_node->next = ptr->next;	new_node->pre = ptr;
					if (ptr->next != nullptr)
						ptr->next->pre = new_node;
					ptr->next = new_node;
					ptr = ptr->next;
				}
			}
		}
		if (T == 0)
			continue;
		while (ptr != &blank) {
			ptr = ptr->pre;
		}
		while (ptr->next != nullptr) {
			printf("%c", ptr->next->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	return 0;
}