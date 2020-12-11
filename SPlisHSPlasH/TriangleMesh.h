#ifndef __TriangleMesh_h__
#define __TriangleMesh_h__

#include <vector>
#include "SPlisHSPlasH/Common.h"

namespace SPH
{
	/** \brief Data structure for a triangle mesh with normals and vertex normals. 
	 */
	class TriangleMesh
	{
	public: 
		typedef std::vector<unsigned int> Faces;
		typedef std::vector<Vector3r> Normals;
		typedef std::vector<Vector3r> Vertices;

	protected:
		Vertices m_x;
        Vertices m_x0;
		Faces m_indices;
		Normals m_normals;
		Normals m_vertexNormals;

	public:
		TriangleMesh();
		~TriangleMesh();

		void release();
		void initMesh(const unsigned int nPoints, const unsigned int nFaces);
		/** Add a new face.	*/
		void addFace(const unsigned int * const indices);
		/** Add a new face.	*/
		void addFace(const int * const indices);
		/** Add new vertex. */
		void addVertex(const Vector3r &vertex);

        void addVertex0(const Vector3r &vertex);

        void translateVertices(const Vector3r &translation);

        void rotateVertices(const Matrix3r &rotation);

        void setFaces(const Faces &faces);

        void setVertices(const Vertices &vertices);

		const Faces& getFaces() const { return m_indices; }
		Faces& getFaces(){ return m_indices; }
		const Normals& getFaceNormals() const { return m_normals; }
		Normals& getFaceNormals(){ return m_normals; }
		const Normals& getVertexNormals() const { return m_vertexNormals; }
		Normals& getVertexNormals(){ return m_vertexNormals; }
		const Vertices& getVertices() const { return m_x; }
		Vertices& getVertices() { return m_x; }
        Vertices& getVertices0() { return m_x0; }

		unsigned int numVertices() const { return static_cast<unsigned int>(m_x.size()); }
		unsigned int numFaces() const { return (unsigned int)m_indices.size() / 3; }

		void updateNormals();
		void updateVertexNormals();
	};

}

#endif
