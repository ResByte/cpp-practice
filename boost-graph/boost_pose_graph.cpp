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
#include <Eigen/Dense>

//create custom vertex property
struct Pose{
	int key;
	std::vector<double>  data;
	};
struct constraints{
	Eigen::Matrix4f transformation;
	
	};




//Property types 
typedef boost::property<boost::edge_weight_t,int> EdgeWeightProperty;
typedef boost::property<boost::vertex_name_t,std::string,boost::property<boost::vertex_index2_t,int> > VertexProperties;

//Graph type 
//typedef boost::adjacency_list<boost::vecS,boost::vecS, boost::undirectedS,VertexProperties, EdgeWeightProperty> Graph;
typedef boost::adjacency_list<boost::listS,boost::vecS, boost::undirectedS,Pose, constraints> Graph;

// create hte vertices
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

//create edges 
typedef boost::graph_traits<Graph>::edge_descriptor Edge;

void createGraph(){
	Graph g;
	
	Vertex v1 ;
	v1 = boost::add_vertex(g);
	g[v1].key = 40;
	g[v1].data.assign(3,2.0);
	
	Vertex v2 ;
	v2 = boost::add_vertex(g);
	g[v2].key = 21;
	g[v2].data.assign(3,4.0);
	
	Vertex v3 ;
	v3 = boost::add_vertex(g);
	g[v3].key = 34;
	g[v3].data.assign(3,5.0);
	
	
	Edge e1; 
	e1 = (boost::add_edge(v1,v2,g)).first;
	g[e1].transformation << 1,0,0,0,
							0,2,2,0,
							0,0,3,0,
							0,0,0,2;  
	
	Edge e2; 
	e2 = (boost::add_edge(v2,v3,g)).first;
	g[e2].transformation << 1,0,0,0,
							0,2,2,0,
							0,0,3,0,
							0,0,0,2;  
	
	
	//Iterate over the graph 
	Graph::vertex_iterator vertexIt,vertexEnd;
	Graph::adjacency_iterator neighbourIt, neighbourEnd;
	
	
	boost::tie(vertexIt, vertexEnd) = boost::vertices(g);
	for(;vertexIt!=vertexEnd;++vertexIt)
	{
		std::cout<<g[*vertexIt].key<<"is connected with";
		boost::tie(neighbourIt,neighbourEnd) = boost::adjacent_vertices(*vertexIt,g);
		for(;neighbourIt != neighbourEnd;++neighbourIt)
		std::cout<<g[*neighbourIt].key<<" ";
		std::cout<<std::endl;
		}
	Graph::edge_iterator edgeIt,edgeEnd;
	boost:tie(edgeIt,edgeEnd) = boost::edges(g);
	for(;edgeIt!=edgeEnd;++edgeIt){
		std::cout<<g[*edgeIt].transformation<<std::endl;
		
		}
	
	
	}




int main(int argc, char **argv)
{
	createGraph();
	return 0;
}

