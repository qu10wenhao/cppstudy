//p1.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	char choose; 												//choose:����Ƿ�Ҫ����Ϸ 
	int games = 0, win = 0;   									//games:�ܵ���Ϸ����, win: Ӯ�ĳ��� 
	
	cout << "��Ҫ����Ϸ��Y/N����";
	cin >> choose;
	
	if ('Y' == choose) do{ 
		games += 1;
		
		int i, j,randnum[3], guessnum[3];						//randnum[3]: 3�������, guessnum[3]: 3���� 
		int chance = 7, rnrp, rnwp;								//count: ��һ�����, rnrp: ������ȷλ�ô���ĸ��� 
																//rnwp: ������ȷλ�ô���ĸ��� 
		srand(time(NULL));
	
		i = 0;
		while (i < 3) {											//����3����ͬ����� 
			bool flag = true;
			randnum[i] = rand() * 10 / (RAND_MAX + 1);
			for (j=0; j<i; j++){
				if (randnum[i] == randnum[j]) {
					flag = false;
				}
			}
			if (flag) {
				i += 1;
			}
		}
	
		while (0 != chance) {									//��ҿ�ʼ�²⣬����Ϊ��ʱǿ�ƽ��� 
			rnrp = 0, rnwp =0;
			cout << "��������²�����֣�" << endl;
			for (i=0; i<3; i++) {
				cin >> guessnum[i];
				}
			
			for (i=0; i<3; i++) {								//�ж�������ȷλ����ȷ��������ȷ
				for (j=0; j<3; j++) {							//λ�ô���ĸ��� 
					if (guessnum[i] == randnum[j]) {
						i == j ? rnrp += 1 : rnwp += 1;
					}
				}
			}
			
			if (3 == rnrp) {									//��Ҳų����֣���ǰ������Ϸ��ʤ����+1 
				cout << "��ϲ����¶��ˣ�" << endl;
				win += 1;
				break;
			}else {												//���δ�³����֣�������Ӧ��ʾ������һ�λ��� 
				cout << rnrp << 'A' << rnwp << 'B' << endl;
				chance -= 1;
			}
				
		}
		
		if (0 == chance) {										//�������������ǿ�ƽ�����Ϸ��������ȷ�� 
			cout << "���ź�����û���ڹ涨�����ڲŶԡ����� ";
			for (i=0; i<3; i++) {
				cout << randnum[i];
				}
			cout << endl;
		}
		cout << "��Ҫ����Ϸ��Y/N����";
		cin >> choose;
	}while ('Y' == choose);
	
	cout << "��һ������" << games << "�֣�Ӯ��" << win\
	 << "�֣�����" << games - win << "��" << endl;				//��Ϸ���������ͳ�ƽ�� 
	return 0; 
}
