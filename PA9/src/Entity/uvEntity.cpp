#include "uvEntity.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//

/**
 * @brief      Constructor for UVEntity.
 *
 * @param[in]  pathToModel    The path to this object's model.
 * @param[in]  pathToTexture  The path to this object's texture.
 */
UVEntity::UVEntity( QString pathToModel, QString pathToTexture )
    :   m_pathToModel( pathToModel ), m_pathToTexture( pathToTexture )
{
    ModelLoader::loadUVModel( m_pathToModel, m_model, m_numVertices );
}

/**
 * @brief      Destructor for UVEntity.
 */
UVEntity::~UVEntity()
{
    teardownGL();
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
//

/**
 * @brief      Initializes the OpenGL data for drawing.
 */
void UVEntity::initializeGL()
{
    initializeOpenGLFunctions();

    // Create the shader this entity will use
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceFile( QOpenGLShader::Vertex, 
        PATH_TO_V_SHADER );
    m_program->addShaderFromSourceFile( QOpenGLShader::Fragment, 
        PATH_TO_F_SHADER );
    m_program->link();
    m_program->bind();

    // Cache the Uniform Locations
    m_modelWorld = m_program->uniformLocation( "model_to_world" );
    m_worldEye = m_program->uniformLocation( "world_to_eye" );
    m_eyeClip = m_program->uniformLocation( "eye_to_clip" );

    // Create the Texture Buffer Object
    m_texture = new QOpenGLTexture( QImage( m_pathToTexture ).mirrored() );
    m_texture->setMinificationFilter( QOpenGLTexture::LinearMipMapLinear );
    m_texture->setMagnificationFilter( QOpenGLTexture::Linear );

    // Create the Vertex Buffer Object
    m_vbo = new QOpenGLBuffer();
    m_vbo->create();
    m_vbo->bind();
    m_vbo->setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vbo->allocate( m_model, m_numVertices * sizeof( m_model[0] ) );

    // Create the Vertex Array Object
    m_vao = new QOpenGLVertexArrayObject();
    m_vao->create();
    m_vao->bind();
    m_program->enableAttributeArray( 0 );
    m_program->enableAttributeArray( 1 );
    m_program->setAttributeBuffer(  0,
                                    GL_FLOAT,
                                    UVVertex::positionOffset(),
                                    UVVertex::PositionTupleSize,
                                    UVVertex::stride() );
    m_program->setAttributeBuffer(  1,
                                    GL_FLOAT,
                                    UVVertex::uvOffset(),
                                    UVVertex::UVTupleSize,
                                    UVVertex::stride() );

    // Release all in order
    m_vao->release();
    m_vbo->release();
    m_texture->release();
    m_program->release();
}

/**
 * @brief      Draws the object to the screen.
 *
 * @param      camera      The camera of the world.
 * @param      projection  The projection of the world.
 */
void UVEntity::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glDisable( GL_CULL_FACE );

    m_program->bind();

    m_program->setUniformValue( m_worldEye, camera.toMatrix() );
    m_program->setUniformValue( m_eyeClip, projection );

    m_vao->bind();
    m_texture->bind();

    m_program->setUniformValue( m_modelWorld, GTransform.toMatrix() );

    glDrawArrays( GL_TRIANGLES, 0, m_numVertices );

    m_texture->release();
    m_vao->release();
    m_program->release();
}

/**
 * @brief      Virtual update function.
 */
void UVEntity::update()
{
}

/**
 * @brief      Helper function to delete OpenGL data.
 */
void UVEntity::teardownGL()
{
    delete m_vbo;
    delete m_vao;
    delete m_program;
    delete m_model;
    delete m_texture;
}