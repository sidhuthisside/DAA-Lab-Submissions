# Assignment No. 5 — SwiftCargo Delivery Routing

## Objective

Find the minimum-cost route from a warehouse to a customer in a staged delivery network, then recompute the route after a road-cost update.

## Files

| File | Description |
|---|---|
| `swiftcargo.cpp` | C++ implementation using dynamic programming over the network's stages. |
| `swiftcargo_output.txt` | Saved program output for the initial and updated delivery requests. |

## Algorithm

The directed graph is arranged in stages. The program initializes the warehouse cost to zero and relaxes outgoing roads in stage order, tracking each node's best known cost and predecessor. It then reconstructs the route to the customer. Because each road moves forward through the stages, this computes a minimum-cost path in the staged graph.

The sample's first route costs `7` via `Warehouse -> B -> D -> Customer`. After the Warehouse-to-B cost increases from `2` to `7`, the best route costs `11` via `Warehouse -> A -> C -> Customer`.

## Compile and Run

Run these commands from this folder:

```bash
g++ -o swiftcargo.exe swiftcargo.cpp
swiftcargo.exe
```

*Assignment submitted for DAA Lab | Academic Year 2025–2026*
