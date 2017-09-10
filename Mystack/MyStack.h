#ifndef MYSTACK_H
#define MYSTACK_H

template <typename T>
class MyStack {
public:
	MyStack(int size);              //�����ڴ��ʼ��ջ�ռ䣬�趨ջ������ջ��
	~MyStack();                      //����ջ�ռ��ڴ�
	bool stackEmpty();            //�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true���ǿշ���false
 	bool stackFull();                 //�ж�ջ�Ƿ�Ϊ����Ϊ������true, Ϊ������false
	void clearStack();               //���ջ
	int stackLength();              //����Ԫ�صĸ���
	bool push(T elem);        //Ԫ����ջ��ջ������
	bool pop(T &elem);       //Ԫ�س�ջ��ջ���½�
	void stackTraverse(bool isFromButtom);          //����ջ�е�����Ԫ��

private:
	T *m_pBuffer;     //ջ�ռ�ָ��
	int m_iSize;                        //ջ����
	int m_iTop;                        //ջ��
};

template <typename T>
MyStack<T>::MyStack(int size) {
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack() {
	delete[]m_pBuffer;
}

template <typename T>
bool MyStack<T>::stackEmpty() {
	return m_iTop ? false : true;
}

template <typename T>
bool MyStack<T>::stackFull() {
	if (m_iTop == m_iSize) {
		return true;
	}
	return false;
}

template <typename T>
void MyStack<T>::clearStack() {
	m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength() {
	return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem) {
	if (stackFull()) {
		return false;
	}
	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem) {
	if (stackEmpty()) {
		return false;
	}
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromButton) {
	if (isFromButton) {
		for (int i = 0; i < m_iTop; i++) {
			cout << m_pBuffer[i];
			//m_pBuffer[i].printCoordinate();
		}
	}
	else {
		for (int i = m_iTop - 1; i >= 0; i--) {
			cout << m_pBuffer[i];
			//m_pBuffer[i].printCoordinate();
		}
	}

}
#endif
