#pragma once

#include <vector>
#include "Serialized/Metadata.hpp"
#include "VertexWeights.hpp"

namespace acid
{
	class ACID_EXPORT SkinLoader
	{
	public:
		SkinLoader(const Metadata *libraryControllers, const uint32_t &maxWeights);

		const std::vector<std::string> &GetJointOrder() const { return m_jointOrder; }

		const std::vector<VertexWeights> &GetVertexWeights() const { return m_vertexWeights; }
	private:
		void LoadJointsList();

		std::vector<float> LoadWeights();

		std::vector<uint32_t> GetEffectiveJointsCounts(const Metadata *weightsDataNode);

		void GetSkinWeights(const Metadata *weightsDataNode, const std::vector<uint32_t> &counts, const std::vector<float> &weights);

		const Metadata *m_skinData;
		uint32_t m_maxWeights;

		std::vector<std::string> m_jointOrder;
		std::vector<VertexWeights> m_vertexWeights;
	};
}
