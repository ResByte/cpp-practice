/*
 * demoGraph.cpp
 * Description: This is the class for pose graph construction.
 * 				It is used for the development of pose graph SLAM in robotics.
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
#include <boost/graph/graphviz.hpp>


class PoseGraph{
	/*
	 * This is the default class to create Graphs using adjacency list.
	 * The methods included here are addVertex, addEdge(), display() 
	 * 
	 * 
	 * 
	 */ 
	private:
		// Custom vertex properties as Pose
		struct pose_{
			int key;
			std::vector<double>  data;
		};
		
		// Custom edge properties as constraints
		struct constraints_{
			Eigen::Matrix4f transformation;
		};
		//typedef boost::property<boost::edge_weight_t,int> EdgeWeightProperty_;
		//typedef boost::property<boost::vertex_name_t,std::string,boost::property<boost::vertex_index2_t,int> > VertexProperties_;

		//Graph type 
		typedef boost::adjacency_list<boost::listS,boost::vecS, boost::undirectedS,pose_, constraints_> Graph_;
		typedef boost::graph_traits<Graph_>::vertex_descriptor Vertex_;
		typedef boost::graph_traits<Graph_>::edge_descriptor Edge_;
		Graph_ gr_;
	public:
	// Add vertex to the graph
	void addVertex(int v);
	// Add edge in betwwen the last 2 vertices of the graph
	void addEdgeToPrev();
	// Print the graph
	void display();
	
	};

/*
 * This Function adds the vertex to the graph with the parameter as index of the vertex
 */ 
	
void PoseGraph::addVertex(int v){
	Vertex_ v1;
	v1 = boost::add_vertex(gr_);
	gr_[v1].key = v ;
	gr_[v1].data.assign(3,4.0);
	return;
	}

/*
 * This function adds an edge between the last 2 add vertices.
 * The parameter taken is the transformation matrix. 
 */ 
void PoseGraph::addEdgeToPrev(){
	Graph_::vertex_iterator vertexIt,vertexEnd;
	boost::tie(vertexIt, vertexEnd) = boost::vertices(gr_);
	
	Edge_ e1; 
	e1 = (boost::add_edge(*(vertexEnd-1),*vertexEnd,gr_)).first;
	gr_[e1].transformation <<1,0,0,0,
							0,2,2,0,
							0,0,3,0,
							0,0,0,2;  
	
	return;
	}
	
	
/*
 * This function print out the current graph.
 */ 
void PoseGraph::display(){
	boost::write_graphviz(std::cout, gr_);
	return;
	}
int main(int argc, char **argv)
{ 	
	PoseGraph pg;
	pg.addVertex(0);
	for (int i= 1;i < 10 ; i++) {pg.addVertex(i); pg.addEdgeToPrev();}
	pg.display();
	return 0;
}

