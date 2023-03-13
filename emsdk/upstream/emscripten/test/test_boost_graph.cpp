/* Boost Graph example, from Boost-Cookbook + minor adaptations for testcase
   source: https://github.com/apolukhin/Boost-Cookbook/blob/second_edition/Chapter12/01_graph/main.cpp

  Boost Software License - Version 1.0 - August 17th, 2003

  Permission is hereby granted, free of charge, to any person or organization
  obtaining a copy of the software and accompanying documentation covered by
  this license (the "Software") to use, reproduce, display, distribute,
  execute, and transmit the Software, and to prepare derivative works of the
  Software, and to permit third-parties to whom the Software is furnished to
  do so, all subject to the following:

  The copyright notices in the Software and this entire statement, including
  the above license grant, this restriction and the following disclaimer,
  must be included in all copies of the Software, in whole or in part, and
  all derivative works of the Software, unless such copies or derivative
  works are solely in the form of machine-executable object code generated by
  a source language processor.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
  SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
  FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*/

#include <boost/graph/adjacency_list.hpp>
#include <string>

typedef std::string vertex_t;

typedef boost::adjacency_list <
boost::vecS,
boost::vecS,
boost::bidirectionalS,
vertex_t> graph_type;

#include <boost/utility/string_ref.hpp>
#include <iostream>

inline bool find_and_print( const graph_type& graph, boost::string_ref name ) {
  typedef boost::graph_traits<graph_type>::vertex_iterator vert_it_t;

  vert_it_t it, end;
  boost::tie(it, end) = boost::vertices(graph);

  typedef boost::graph_traits<graph_type>::vertex_descriptor desc_t;

  for ( ; it != end; ++it ) {
    const desc_t desc = *it;
    const vertex_t& vertex = boost::get(boost::vertex_bundle, graph)[desc];

    if ( vertex == name.data()) {
      break;
    }
  }

  if ( it != end ) {
    std::cout << name << '\n';
    return true;
  }
  else {
    return false;
  }
}

int main() {
  graph_type graph;

  static const std::size_t vertex_count = 5;
  graph.m_vertices.reserve(vertex_count);

  typedef boost::graph_traits<graph_type>::vertex_descriptor descriptor_t;

  descriptor_t cpp = boost::add_vertex(vertex_t("C++"), graph);
  descriptor_t stl = boost::add_vertex(vertex_t("STL"), graph);
  descriptor_t boost = boost::add_vertex(vertex_t("Boost"), graph);
  descriptor_t guru = boost::add_vertex(vertex_t("C++ guru"), graph);
  descriptor_t ansic = boost::add_vertex(vertex_t("C"), graph);

  BOOST_STATIC_ASSERT(( boost::is_same<descriptor_t, std::size_t>::value ));

  boost::add_edge(cpp, stl, graph);
  boost::add_edge(stl, boost, graph);
  boost::add_edge(boost, guru, graph);
  boost::add_edge(ansic, guru, graph);

  if ( find_and_print(graph, "Boost") ) {
    return 0;
  }
  else {
    return 1;
  }
}
