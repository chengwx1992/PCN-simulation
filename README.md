# NS-3 simulator for PCN，DCQCN，QCN and Timely
This is based on [bobzhuyb/ns3-rdma](https://github.com/bobzhuyb/ns3-rdma) to compare different congestion control algorithms for RDMA over Converged Ethernet v2 (RoCEv2). Different algorithms are implemented in separated branches and please check the following papers for reference.

- PCN: *Re-architecting Congestion Management in Lossless Ethernet*, NSDI'20

- DCQCN: *Congestion Control for Large-scale RDMA Deployments*, SIGCOMM'15

- QCN: *IEEE 802.1 Qau - Congestion Notification*, [802-1qau](https://1.ieee802.org/dcb/802-1qau/)

- TIMELY: *TIMELY: RTT-based Congestion Control for the Datacenter*, SIGCOMM'15