#include <Adorn/Renderer/Window.h>
#include <Adorn/Renderer/GraphicContext.h>
#include <Adorn/Renderer/RenderFactory.h>
#include <Adorn/Renderer/Shader.h>
#include <Adorn/Renderer/ShaderProgram.h>
#include <Adorn/Renderer/Buffer.h>
#include <Adorn/Renderer/Primitive.h>
#include <Adorn/Core/Scene.h>
#include <Adorn/Core/Node.h>
#include <Adorn/Core/Pipeline.h>

#include <gl\GL.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR  lpCmdLine, int nCmdShow) {
	
	Adorn::Window *window = new Adorn::Window(L"Simple Window", 800, 600, hInstance);
	Adorn::GraphicContext *gc = Adorn::GraphicContext::create(Adorn::GraphicContext::OPENGL);	
	
	window->setContext(gc);
	window->create();

	float color[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
	gc->setClearColor(color);

	Adorn::RenderFactory *renderFactory = gc->getRenderFactory();

	Adorn::Shader *vertexShader = renderFactory->createShader();
	Adorn::Shader *pixelShader = renderFactory->createShader();

	Adorn::ShaderProgram  *shaderProgram = renderFactory->createShaderProgram();
	Adorn::Buffer *buffer = renderFactory->createBuffer();

	Adorn::Primitive *primitive = renderFactory->createPrimitive();
	primitive->setStartIndex(0);
	primitive->setIndexCount(3);
	primitive->setPrimitiveType(Adorn::Primitive::TRIANGLE_STRIP);


	float points[] = {
		0.0f,	0.5f,	0.0f,
		0.5f, -0.5f,	0.0f,
		-0.5f, -0.5f,	0.0f
	};

	Adorn::BufferAttribute bufferAttribute(Adorn::BufferAttribute::VERTEX, 
										   points, 
										   9 * sizeof(float), 
										   Adorn::BufferAttribute::STATIC);

	bufferAttribute.addVertexAttribute(Adorn::VertexAttribute(Adorn::VertexAttribute::POSITION, 
															  0, 3, 0, NULL));
	buffer->addBufferAttribute(bufferAttribute);
	buffer->setPrimitive(primitive);
	
	const char* vertex_shader =
		"#version 410\n"
		"in vec3 vp;"
		"void main () {"
		"	gl_Position = vec4 (vp, 1.0);"
		"}";
	
	
	const char* fragment_shader =
		"#version 410\n"
		"out vec4 frag_colour;"
		"void main () {"
		"	frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
		"}";

	vertexShader->setShaderType(Adorn::Shader::VERTEX);
	pixelShader->setShaderType(Adorn::Shader::PIXEL);

	vertexShader->setShaderSource(vertex_shader);
	pixelShader->setShaderSource(fragment_shader);

	shaderProgram->attach(vertexShader);
	shaderProgram->attach(pixelShader);

	Adorn::Pipeline *pipeline = new Adorn::Pipeline();

	pipeline->setBuffer(buffer);
	pipeline->setShader(shaderProgram);

	Adorn::Node *node = new Adorn::Node();
	node->setPipeline(pipeline);

	window->show();

	Adorn::Scene *scene = new Adorn::Scene();
	scene->addNode(node);

	gc->setScene(scene);

	window->run();

	delete window;

	return 0;
}
