#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
typedef std::pair<int, int> Edge;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  boost::property<boost::vertex_distance_t, int>, 
  boost::property<boost::edge_weight_t, int>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef Graph::edge_property_type Weight;

std::pair<po::options_description, po::variables_map> ParseProgramOptions(int argc, char *argv[]) {
  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
      ("inputGraph", po::value<std::string>(), "input file name")
      ("outputGraph.dot", po::value<std::string>(), "graph description in dot-format")
      ("outputMST.dot", po::value<std::string>(), "MST in dot-format")
      ("outputCriticalAndPseudocriticalEdges.dot", po::value<std::string>(), 
       "critical and pseudo-critical edges in dot-format")
  ;
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);
  return {desc, vm};
}

Graph ReadGraph(const po::variables_map& vm, const std::string& filename) {
  std::ifstream input(filename);

  int n;
  input >> n;

  std::vector<Edge> edges;
  std::vector<int> weights;
  Edge current_edge;
  int weight;
  while (input >> current_edge.first >> current_edge.second >> weight) {
    edges.push_back(current_edge);
    weights.push_back(weight);
  }

  Graph graph(edges.begin(), edges.end(), weights.begin(), n);
  return graph;
}

void PrintGraph(const Graph& graph, const std::string& filename) {
  std::ofstream output(filename);
  boost::write_graphviz(output, graph);
}

Graph BuildMST(const Graph& graph) {
  std::vector<Vertex> parents(boost::num_vertices(graph));
  std::map<Vertex, double> distances;
  auto root = boost::vertex(0, graph);

  prim_minimum_spanning_tree(graph, parents.data(),
          boost::root_vertex(root)
          .distance_map(boost::make_assoc_property_map(distances)));

  Graph mst;
  for (Vertex v = 0; v < boost::num_vertices(graph); ++v) {
    if (parents[v] == v) continue;
    boost::add_edge(boost::vertex(v, graph), boost::vertex(parents[v], graph), distances[v]), graph);
  }

  return mst;
}

int main(int argc, char *argv[]) {
  auto [desc, vm] = ParseProgramOptions(argc, argv);
  if (vm.count("help")) {
      std::cout << desc << "\n";
      return 1;
  }

  auto graph = ReadGraph(vm, vm["inputGraph"].as<std::string>());
  if (vm.count("outputGraph.dot")) {
    PrintGraph(graph, vm["outputGraph.dot"].as<std::string>());
  }
  if (vm.count("outputMST.dot")) {
    auto mst = BuildMST(graph);
    PrintGraph(mst, vm["outputMST.dot"].as<std::string>());
  }
}