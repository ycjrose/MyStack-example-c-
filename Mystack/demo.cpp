#include "MyStack.h"
#include "Coordinate.h"
#include <iostream>
#include <cstdlib>
#include "stdlib.h"
using namespace std;

//int main(void) {
//	MyStack<char> *pStack = new MyStack<char>(5);
//
//	//pStack->push('h'); //µ×
//	//pStack->push('e');
//	//pStack->push('l');
//	//pStack->push('l');
//	//pStack->push('o'); //¶¥
//
//	pStack->push('h');
//	pStack->push('x');
//
//	pStack->stackTraverse(true);
//	//pStack->clearStack();
//
//	char elem = 0;
//	//Coordinate elem;
//	pStack->pop(elem);
//	cout << elem <<endl;
//	pStack->stackTraverse(false);
//
//	cout << pStack->stackLength() << endl;
//
//	if (pStack->stackEmpty()) {
//		cout << "Õ»Îª¿Õ" << endl;
//	}
//	if (pStack->stackFull()) {
//		cout << "Õ»ÎªÂú" << endl;
//	}
//	delete pStack;
//	pStack = NULL;
//
//	system("pause");
//	return 0;
//}
//#define BINARY 2
//#define OCTONARY 8
//#define HEXADECIMAL 16

//int main(void) {
//	MyStack<int> *pStack = new MyStack<int>(40);
//	char num[] = "0123456789ABCDEF";
//	int N = 2010;
//	int mod = 0;
//	while (N != 0) {
//		mod = N % HEXADECIMAL;
//		N = N / HEXADECIMAL;
//		pStack->push(mod);
//	}
//	//pStack->stackTraverse(false);
//	int elem = 0;
//	//while (!pStack->stackEmpty()) {
//	//	pStack->pop(elem);
//	//	cout << num[elem] ;
//	//}
//	for (int i = pStack->stackLength() - 1; i >= 0; i--) {
//		pStack->pop(elem);
//		cout << num[elem];
//	}
//
//	delete pStack;
//	pStack = NULL;
//
//	system("pause");
//	return 0;
//}
int main(void) {//À¨ºÅÆ¥Åä
	MyStack<char> *pStack = new MyStack<char>(30);

	MyStack<char> *pNeedStack = new MyStack<char>(30);

	char str[] = "[()]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]";
	char currentNeed = 0;

	for (int i = 0; i < strlen(str) ; i++) {
		bool flag = false;
		//Ò»µ©²»Æ¥Åä£¬Ìø³öforÑ­»·£¬ÎÞÐë¼ÌÐøÉ¨Ãè
		if (flag) {
			break;
		}
		if (str[i] != currentNeed) {
			pStack->push(str[i]);
			switch (str[i]){
			case '[':
				if (currentNeed != 0) {
					pNeedStack->push(currentNeed);
				}
				currentNeed = ']';
				break;
			case '(':
				if (currentNeed != 0) {
					pNeedStack->push(currentNeed);
				}
				currentNeed = ')';
				break;
			default:
				flag = true;
				break;
			}
		}
		else {
			char elem;
			pStack->pop(elem);
			if (!pNeedStack->pop(currentNeed)) {
				currentNeed = 0;
			};
		}
	}

	if (pStack->stackEmpty()) {
		cout << "·ûºÅÕýÈ·Æ¥Åä" << endl;
	}
	else {
		cout << "²»ÕýÈ·" << endl;
	}

	delete pStack;
	pStack = NULL;
	delete pNeedStack;
	pNeedStack = NULL;

	system("pause");
	return 0;
}