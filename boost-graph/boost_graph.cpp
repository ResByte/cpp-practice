/*
 * boost_graph.cpp
 * 
 * Copyright 2014 abhinav <abhinav@abhinav-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <boost/config.hpp>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/property_map/property_map.hpp>

//Property types 
typedef boost::property<boost::edge_weight_t,int> EdgeWeightProperty;
typedef boost::property<boost::vertex_name_t,std::string,boost::property<boost::vertex_index2_t,int> > VertexProperties;

//Graph type 
typedef boost::adjacency_list<boost::vecS,boost::vecS, boost::undirectedS,VertexProperties, EdgeWeightProperty> Graph;

// create hte vertices
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

//create edges 
typedef boost::graph_traits<Graph>::edge_descriptor Edge;

void createGraph(){
	Graph g;
	boost::property_map<Graph,boost::vertex_name_t>::type city_name  = boost::get(boost::vertex_name,g);
	boost::property_map<Graph,boost::vertex_index2_t>::type city_index2 = boost::get(boost::vertex_index2,g);
	boost::property_map<Graph,boost::edge_weight_t>::type edge_distance = boost::get(boost::edge_weight, g);
	Vertex u1;
	u1 = boost::add_vertex(g);
	city_name[u1] = "Los Angeles";
	city_index2[u1] = 3;
	
	Vertex u2;
	u2 = boost::add_vertex(g);
	city_name[u2] = "BakersField";
	city_index2[u2] = 2	;
	
	Vertex u3;
	u3 = boost::add_vertex(g);
	city_name[u3] = "New York";
	city_index2[u3] = 1;
	
	//create edges
	Edge e1;
	e1 = (boost::add_edge(u1,u2,g)).first;
	edge_distance[e1] = 100;
	
	Edge e2;
	e2 = boost::add_edge(u1,u3,g).first;
	edge_distance[e2] = 24000;
	
	
	}




int main(int argc, char **argv)
{
	createGraph();
	return 0;
}

