#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <vector>
#include <boost/tuple/tuple.hpp>
int main()
{
	boost::adjacency_list<> g(4); // create a graph represented by adjacency list
	boost::add_edge(1,2,g); // add edge to the graph
	boost::add_edge(0,2,g);
	boost::add_edge(2,3,g);
	boost::add_edge(0,1,g);
	boost::graph_traits<boost::adjacency_list<> >::vertex_iterator i, end; // iterator for the nodes 
	boost::graph_traits<boost::adjacency_list<> >::adjacency_iterator ai,a_end; // iterator for the adjacency list of each node
	boost::property_map<boost::adjacency_list <>,boost::vertex_index_t>::type index_map = get(boost::vertex_index,g); // property map to get vertex property like vertex_index
	for(boost::tie(i,end) = boost::vertices(g);i!=end;++i)
	{
		boost::tie(ai,a_end) = boost::adjacent_vertices(*i,g);// tie is used to make tuple with elements of non-const references type
		if (ai == a_end)
		{
			std::cout<<"has no children"<<std::endl;
		
		}else{
			std::cout<<"is the parent"<<std::endl;

	
		}

		for(;ai!=a_end;++ai)
		{
			std::cout<<boost::get(index_map,*ai)<<std::endl;		
		}
	
	}

	return 0;
}
