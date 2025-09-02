#ifndef AXON_H
#define AXON_H

#include "PreDeclare.hpp"
#include "Synapse.hpp"

class Axon : public Synapse {
public:
    Axon() = default;
    Axon(const Neuron* Owner);
    Axon& operator=(const Axon& source);

    ~Axon() override;

    // 克隆函数（重写纯虚函数）
    Axon* Clone() const override;

    bool AddConnection(Dendrite* Target);
    bool RemoveConnection(Dendrite* Target);
    bool RemoveAllConnection();

protected:
    
    using Synapse::IsValidInput;
    // 重写数据转换函数（实现突触信号传递逻辑）
    vector<double> Transform() override;

    vector<Dendrite*> m_ConnectedDendrites {}; // 连接的突触列表
    const double m_Weight {1.0};

public:
    //Getter
    const vector<Dendrite*>& ConnectedDendrites {m_ConnectedDendrites};
    const double& Weight {m_Weight};
};

#endif /*AXON_H */