// trsys_CMake.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <fstream>
#include "trsys_CMake.h"

#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")

using namespace std;



void init_screen(void)
{
	glMatrixMode(GL_PROJECTION);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}


void reshape_saddle21(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 7.1, -9.0, 10.1);


	float lx = 0.17f, lz = 0.0f;
	float x = -5.4f, z = 2.4f;
	gluLookAt(x, 1.4f, z,
		x + lx, 0.1f, z + lz,
		0.2f, 1.2f, -0.05f);

	glMatrixMode(GL_MODELVIEW);
}

void reshape_saddle3(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 12, 0, 12);
	glTranslatef(-1.0, 0.0, -3.0);
	glRotatef(-30, 0, 0, 1);
	glRotatef(-30, 1, 0, 0);
	glRotatef(10, 0, 1, 0);
	
	glMatrixMode(GL_MODELVIEW);
}

void reshape_saddle7(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 7, -9, 10);
	glTranslatef(7.0, 5.0, 5.0);
	glRotatef(-31, 0, 0, 1);
	glRotatef(-31, 1, 0, 0);
	glRotatef(201, 0, 1, 0);


	glMatrixMode(GL_MODELVIEW);
}


boost::scoped_ptr <triangle_service> t(new triangle_service());


int main(int argc, char *argv[])
{

	int i = 0, j = 0;// , i1 = 0, i2 = 1, *i2_p = nullptr;
	//i2_p = &i2;
	float sc = 0;
	char *buff = new char[1000];

	ifstream inn;

	linear_calculation *l = new linear_calculation();


	while (j < argc) {
		switch (j) {
		case 0:
			if (argc != 6) {
				cout << "Invalid parametres!!!" << endl;
				return 1;
			}
			break;
		case 1:
			if (strlen(argv[j]) != 2 || strstr(argv[j], "-i") == NULL) {
				cout << "Invalid key parametres!!!" << endl;
				return 1;
			}
			break;
		case 2:
			inn.open(argv[j]);
			if (!inn) {
				cout << "Can't read file!!!" << endl;
				return 1;
			}
			break;
		case 3:
			if (strlen(argv[j]) != 2 || strstr(argv[j], "-o") == NULL) {
				cout << "Invalid key parametres!!!" << endl;
				return 1;
			}
			break;

		}

		j++;
	}
	j = 0;

	
	while (inn.getline(buff, 1000)) {

		t->pars(buff);
		t->coo.i = i;
		if (i > 0) {
			sc = t->scalar_prod(t->coo);
			t->coord_m.emplace(sc, t->coo);
			t->coord_m0.emplace(i, t->coo);
		}
		i++;

		memset(buff, 0, strlen(buff));
	}


	t->space_scan(t->coord_mp0, t->coord_m);
	l->pakgage_func(t->max_i, t->max_j, t->triangle_p, t->triangl_tr);
	
	
	ofstream outt, outt0;

	outt.open("C:\\Users\\c\\source\\repos\\p1.txt", ios::app);

	//for the formatting out 

	auto ex_arr = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[0];
			try {
				v[0].at(0);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[0].at(0);
	};

	auto ex_arr1 = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[0];
			try {
				v[0].at(1);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[0].at(1);
	};

	auto ex_arr00 = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[1];
			try {
				v[1].at(0);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[1].at(0);
	};
	auto ex_arr01 = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[1];
			try {
				v[1].at(1);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[1].at(1);
	};
	auto ex_arr10 = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[2];
			try {
				v[2].at(0);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[2].at(0);
	};
	auto ex_arr11 = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[2];
			try {
				v[2].at(1);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[2].at(1);
	};

	auto ex_arr20 = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[3];
			try {
				v[3].at(0);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[3].at(0);
	};
	auto ex_arr21 = [](boost::container::small_vector<boost::array<int, 2>, 3> v) {

		try {
			v[3];
			try {
				v[3].at(1);
			}
			catch (out_of_range &e) {
				cout << e.what() << endl;
				return 0;
			}
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return 0;
		}

		return v[3].at(1);
	};

	
	for (auto &m1 : t->triangle) { // print nodes
		cout << m1.first << "  " << m1.second.first.node1 << "  " << m1.second.first.node2 << "  " << m1.second.first.node3 << " arr_dead_edg: " << ex_arr(m1.second.second) << " " << ex_arr1(m1.second.second) << "   " << ex_arr00(m1.second.second) << " " << ex_arr01(m1.second.second) << "   " << ex_arr10(m1.second.second) << " " << ex_arr11(m1.second.second) << endl;
		outt << m1.first << "," << m1.second.first.node1 << "," << m1.second.first.node2 << "," << m1.second.first.node3 << " arr_dead_edg: " << ex_arr(m1.second.second) << " " << ex_arr1(m1.second.second) << "   " << ex_arr00(m1.second.second) << " " << ex_arr01(m1.second.second) << "   " << ex_arr10(m1.second.second) << " " << ex_arr11(m1.second.second) << endl;
	}

	outt.close();

	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);                    // window size
	glutInitWindowPosition(500, 500);                // distance from the top-left screen
	init_screen();
	glutCreateWindow("trsystems");    // message displayed on top bar window
	glutDisplayFunc([]() {t->displayMe(); });
	glutReshapeFunc(reshape_saddle21);
	glutMainLoop();
	
	//system("pause");
}
