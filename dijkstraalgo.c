Dijkstra(G)

{ for each v ∈ V

d[v] = ∞;

d[s] = 0; S = ∅; Q = V;

while (Q ≠ ∅)

u = ExtractMin(Q);

S = S U {u};

for each v ∈ u->Adj[]

if (d[v] > d[u]+w(u,v))

d[v] = d[u]+w(u,v);