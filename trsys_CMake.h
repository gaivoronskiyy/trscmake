#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <math.h>
#include <chrono>
#include <thread>
#include <boost/optional.hpp>
#include <boost/rational.hpp>
#include <boost/math/special_functions.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/move/unique_ptr.hpp>
#include <boost/array.hpp>
#include <boost/container/map.hpp>
#include <boost/container/small_vector.hpp>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <boost/functional/hash.hpp>
#include <boost/function.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>



class triangle_service {
public:
	triangle_service() : coo_p(&coo), nodes_p(&nodes), triangle_p(&triangle), triangle_tw0(&triangle_tw), tr_plan_p(&tr_plan), d_key(&dead_key), d_key1(&dead_key1), d_point(&dead_point), coord_mp0(&coord_m0), i1_p(&i1), i2_p(&i2){};
	virtual ~triangle_service() {};
	
	struct coord {
		int i;
		float x;
		float y;
		float z;
	} coo_s{ 0,0,0,0 }, coo{ 0,0,0,0 }, *coo_p;
	

	struct tr_node {
		int node1;
		int node2;
		int node3;
	} nodes{0,0,0}, *nodes_p;

	int pars(char *buff);
	float scalar_prod(coord c);
	bool get_free_nodes(boost::container::small_vector<int*, 3> a, boost::container::small_vector<boost::array<int, 2>, 3> b, bool &nod1, bool &nod2, bool &nod3);
	void get_free_nodes0(boost::container::small_vector<boost::array<int, 2>, 3> a, boost::container::small_vector<boost::array<int, 2>, 3> b, bool &nod1, bool &nod2, bool &nod3);
	bool get_dead_nodes(boost::container::small_vector<boost::array<int, 2>, 3> *a_p, boost::container::small_vector<boost::array<int, 2>, 3> a, boost::container::small_vector<boost::array<int, 2>, 3> b, int f);
    int space_scan(boost::container::map<int, coord> *coord_mp, boost::container::map<float, coord> &coord_m);
	size_t hash_umap(std::pair<float, float>);
	void displayMe();

	boost::unordered_set<int> dead_key, *d_key, dead_key1, *d_key1, dead_point, *d_point;
	boost::container::map<float, coord> coord_m;
	boost::container::map<int, coord> coord_m0, *coord_mp0;
	typedef boost::function<size_t(std::pair<float, float>)> has;
	boost::container::map<int, coord>::iterator it_coord;
	boost::container::small_vector<boost::array<int, 2>, 3> edg{ {0,0},{0,0},{0,0} };
	boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> triangle, triangle_tw, *triangle_p, *triangle_tw0;
	boost::container::multimap<double, std::pair<tr_node, std::pair<int, boost::array<int, 2>>>> triangl_tr;
	boost::container::map<int, std::pair<tr_node, boost::array<float, 4>>> tr_plan, *tr_plan_p;
	std::pair<float, float> key;
	int max_i = 0, max_j = 0;
	int tmp_i0 = 0, tmp_i = 0, i1 = 0, i2 = 1, *i1_p = nullptr, *i2_p = nullptr;
	
};


class linear_calculation : public triangle_service {
public:
	linear_calculation(){};
	~linear_calculation() {};


	bool create_triangle(int point, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_p, boost::container::multimap<double, std::pair<tr_node, std::pair<int, boost::array<int, 2>>>> &triangl_tr);
	bool create_triangle_closed(boost::container::map<int, coord>::iterator it_coord, boost::container::map<int, coord> coord_m0, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> triangle, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_p, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_tw0, tr_node *nodes_p, int &i2, int *i2_p, boost::unordered_set<int> *d_key, boost::unordered_set<int> *d_key1, boost::container::map<int, std::pair<tr_node, boost::array<float, 4>>> *tr_plan_p, boost::container::map<float, coord> coord_m);
	void plan(int *i2_p, tr_node *nodes_p, boost::container::map<int, coord> coord, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_p, boost::container::map<int, std::pair<tr_node, boost::array<float, 4>>> *tr_pl);
	int intersection_triangle(double key_tmp_tr, int point, int flag);
	bool linker_tr(int point, int point1, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_p, boost::container::multimap<double, std::pair<tr_node, std::pair<int, boost::array<int, 2>>>> &triangl_tr);
	bool dis11(std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>> a, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>> b, boost::container::map<int, coord> coord_m0, boost::array<int, 3> *tr0_p, boost::container::small_vector<boost::array<int, 2>, 3> *edge_tr1_p, bool inter);
	bool alone_plan(int t_n0, int t_n1, boost::container::map<int, std::pair<tr_node, boost::array<float, 4>>> *tr_plan_p);
	bool edge_check(boost::container::small_vector<boost::array<int, 2>, 3> a, boost::container::small_vector<boost::array<int, 2>, 3> b, int l);
	void weight(int mls);
	bool tr_alg(int x, int y, int max_i, int max_j, int t_i, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_p, boost::container::multimap<double, std::pair<tr_node, std::pair<int, boost::array<int, 2>>>> &triangl_tr);
	bool tr_link_alg(int p, int x, int y, int max_i, int max_j, int i0, int j0, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_p, boost::container::multimap<double, std::pair<tr_node, std::pair<int, boost::array<int, 2>>>> &triangl_tr);
	void pakgage_func(int max_i, int max_j, boost::container::map<int, std::pair<tr_node, boost::container::small_vector<boost::array<int, 2>, 3>>> *triangle_p, boost::container::multimap<double, std::pair<tr_node, std::pair<int, boost::array<int, 2>>>> &triangl_tr);
	void map_s_print(int max_i, int max_j);


};