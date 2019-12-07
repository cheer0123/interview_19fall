class Graph:
  def __init__(self):
    self.nodes = set()
    self.edges = dict()
    self.distances = {}
    return self
 
  def add_node(self, value):
    self.nodes.add(value)
    return self
 
  def add_edge(self, from_node, to_node, distance):
    self.edges[from_node].append(to_node)
    self.edges[to_node].append(from_node)
    self.distances[(from_node, to_node)] = distance
    return self
 
 
def dijsktra(graph, initial):
  visited = {initial: 0}
  path = {}
 
  nodes = set(graph.nodes)
 
  while nodes: 
    min_node = None
    for node in nodes:
      if node in visited:
        if min_node is None:
          min_node = node
        elif visited[node] < visited[min_node]:
          min_node = node
 
    if min_node is None:
      break
 
    nodes.remove(min_node)
    current_weight = visited[min_node]
 
    for edge in graph.edges[min_node]:
      try:
        weight = current_weight + graph.distance[(min_node, edge)]
      except:
        continue
      if edge not in visited or weight < visited[edge]:
        visited[edge] = weight
        path[edge] = min_node
 
  return visited, path


g = Graph()
g.add_node('a')
g.add_node('b')
g.add_node('c')
g.add_node('d')

g.add_edge('a', 'b', 10)
g.add_edge('b', 'c', 10)
g.add_edge('a', 'c', 15)
g.add_edge('c', 'd', 20)

print(dijsktra(g, 'a'))


