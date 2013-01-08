/** Auto generated by the gl3w_gen.py script **/
//glcoreab.h defines gl types and the gl header
#ifndef __gltypes_h_
#define __gltypes_h_
#endif

#ifndef __gl_h_
#define __gl_h_
#endif

#ifndef __gl3w_h_
#define __gl3w_h_

#include "glcorearb.h"

#ifndef __gl_h_
#define __gl_h_
#endif

class GL
{
public:
/* gl3w api */
	static int Init();
	static int IsSupported(int major, int minor);
	static void* GetProcAddress(const char *proc);

/* OpenGL functions */
	static PFNGLCULLFACEPROC CullFace;
	static PFNGLFRONTFACEPROC FrontFace;
	static PFNGLHINTPROC Hint;
	static PFNGLLINEWIDTHPROC LineWidth;
	static PFNGLPOINTSIZEPROC PointSize;
	static PFNGLPOLYGONMODEPROC PolygonMode;
	static PFNGLSCISSORPROC Scissor;
	static PFNGLTEXPARAMETERFPROC TexParameterf;
	static PFNGLTEXPARAMETERFVPROC TexParameterfv;
	static PFNGLTEXPARAMETERIPROC TexParameteri;
	static PFNGLTEXPARAMETERIVPROC TexParameteriv;
	static PFNGLTEXIMAGE1DPROC TexImage1D;
	static PFNGLTEXIMAGE2DPROC TexImage2D;
	static PFNGLDRAWBUFFERPROC DrawBuffer;
	static PFNGLCLEARPROC Clear;
	static PFNGLCLEARCOLORPROC ClearColor;
	static PFNGLCLEARSTENCILPROC ClearStencil;
	static PFNGLCLEARDEPTHPROC ClearDepth;
	static PFNGLSTENCILMASKPROC StencilMask;
	static PFNGLCOLORMASKPROC ColorMask;
	static PFNGLDEPTHMASKPROC DepthMask;
	static PFNGLDISABLEPROC Disable;
	static PFNGLENABLEPROC Enable;
	static PFNGLFINISHPROC Finish;
	static PFNGLFLUSHPROC Flush;
	static PFNGLBLENDFUNCPROC BlendFunc;
	static PFNGLLOGICOPPROC LogicOp;
	static PFNGLSTENCILFUNCPROC StencilFunc;
	static PFNGLSTENCILOPPROC StencilOp;
	static PFNGLDEPTHFUNCPROC DepthFunc;
	static PFNGLPIXELSTOREFPROC PixelStoref;
	static PFNGLPIXELSTOREIPROC PixelStorei;
	static PFNGLREADBUFFERPROC ReadBuffer;
	static PFNGLREADPIXELSPROC ReadPixels;
	static PFNGLGETBOOLEANVPROC GetBooleanv;
	static PFNGLGETDOUBLEVPROC GetDoublev;
	static PFNGLGETERRORPROC GetError;
	static PFNGLGETFLOATVPROC GetFloatv;
	static PFNGLGETINTEGERVPROC GetIntegerv;
	static PFNGLGETSTRINGPROC GetString;
	static PFNGLGETTEXIMAGEPROC GetTexImage;
	static PFNGLGETTEXPARAMETERFVPROC GetTexParameterfv;
	static PFNGLGETTEXPARAMETERIVPROC GetTexParameteriv;
	static PFNGLGETTEXLEVELPARAMETERFVPROC GetTexLevelParameterfv;
	static PFNGLGETTEXLEVELPARAMETERIVPROC GetTexLevelParameteriv;
	static PFNGLISENABLEDPROC IsEnabled;
	static PFNGLDEPTHRANGEPROC DepthRange;
	static PFNGLVIEWPORTPROC Viewport;
	static PFNGLDRAWARRAYSPROC DrawArrays;
	static PFNGLDRAWELEMENTSPROC DrawElements;
	static PFNGLGETPOINTERVPROC GetPointerv;
	static PFNGLPOLYGONOFFSETPROC PolygonOffset;
	static PFNGLCOPYTEXIMAGE1DPROC CopyTexImage1D;
	static PFNGLCOPYTEXIMAGE2DPROC CopyTexImage2D;
	static PFNGLCOPYTEXSUBIMAGE1DPROC CopyTexSubImage1D;
	static PFNGLCOPYTEXSUBIMAGE2DPROC CopyTexSubImage2D;
	static PFNGLTEXSUBIMAGE1DPROC TexSubImage1D;
	static PFNGLTEXSUBIMAGE2DPROC TexSubImage2D;
	static PFNGLBINDTEXTUREPROC BindTexture;
	static PFNGLDELETETEXTURESPROC DeleteTextures;
	static PFNGLGENTEXTURESPROC GenTextures;
	static PFNGLISTEXTUREPROC IsTexture;
	static PFNGLBLENDCOLORPROC BlendColor;
	static PFNGLBLENDEQUATIONPROC BlendEquation;
	static PFNGLDRAWRANGEELEMENTSPROC DrawRangeElements;
	static PFNGLTEXIMAGE3DPROC TexImage3D;
	static PFNGLTEXSUBIMAGE3DPROC TexSubImage3D;
	static PFNGLCOPYTEXSUBIMAGE3DPROC CopyTexSubImage3D;
	static PFNGLACTIVETEXTUREPROC ActiveTexture;
	static PFNGLSAMPLECOVERAGEPROC SampleCoverage;
	static PFNGLCOMPRESSEDTEXIMAGE3DPROC CompressedTexImage3D;
	static PFNGLCOMPRESSEDTEXIMAGE2DPROC CompressedTexImage2D;
	static PFNGLCOMPRESSEDTEXIMAGE1DPROC CompressedTexImage1D;
	static PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC CompressedTexSubImage3D;
	static PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC CompressedTexSubImage2D;
	static PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC CompressedTexSubImage1D;
	static PFNGLGETCOMPRESSEDTEXIMAGEPROC GetCompressedTexImage;
	static PFNGLBLENDFUNCSEPARATEPROC BlendFuncSeparate;
	static PFNGLMULTIDRAWARRAYSPROC MultiDrawArrays;
	static PFNGLMULTIDRAWELEMENTSPROC MultiDrawElements;
	static PFNGLPOINTPARAMETERFPROC PointParameterf;
	static PFNGLPOINTPARAMETERFVPROC PointParameterfv;
	static PFNGLPOINTPARAMETERIPROC PointParameteri;
	static PFNGLPOINTPARAMETERIVPROC PointParameteriv;
	static PFNGLGENQUERIESPROC GenQueries;
	static PFNGLDELETEQUERIESPROC DeleteQueries;
	static PFNGLISQUERYPROC IsQuery;
	static PFNGLBEGINQUERYPROC BeginQuery;
	static PFNGLENDQUERYPROC EndQuery;
	static PFNGLGETQUERYIVPROC GetQueryiv;
	static PFNGLGETQUERYOBJECTIVPROC GetQueryObjectiv;
	static PFNGLGETQUERYOBJECTUIVPROC GetQueryObjectuiv;
	static PFNGLBINDBUFFERPROC BindBuffer;
	static PFNGLDELETEBUFFERSPROC DeleteBuffers;
	static PFNGLGENBUFFERSPROC GenBuffers;
	static PFNGLISBUFFERPROC IsBuffer;
	static PFNGLBUFFERDATAPROC BufferData;
	static PFNGLBUFFERSUBDATAPROC BufferSubData;
	static PFNGLGETBUFFERSUBDATAPROC GetBufferSubData;
	static PFNGLMAPBUFFERPROC MapBuffer;
	static PFNGLUNMAPBUFFERPROC UnmapBuffer;
	static PFNGLGETBUFFERPARAMETERIVPROC GetBufferParameteriv;
	static PFNGLGETBUFFERPOINTERVPROC GetBufferPointerv;
	static PFNGLBLENDEQUATIONSEPARATEPROC BlendEquationSeparate;
	static PFNGLDRAWBUFFERSPROC DrawBuffers;
	static PFNGLSTENCILOPSEPARATEPROC StencilOpSeparate;
	static PFNGLSTENCILFUNCSEPARATEPROC StencilFuncSeparate;
	static PFNGLSTENCILMASKSEPARATEPROC StencilMaskSeparate;
	static PFNGLATTACHSHADERPROC AttachShader;
	static PFNGLBINDATTRIBLOCATIONPROC BindAttribLocation;
	static PFNGLCOMPILESHADERPROC CompileShader;
	static PFNGLCREATEPROGRAMPROC CreateProgram;
	static PFNGLCREATESHADERPROC CreateShader;
	static PFNGLDELETEPROGRAMPROC DeleteProgram;
	static PFNGLDELETESHADERPROC DeleteShader;
	static PFNGLDETACHSHADERPROC DetachShader;
	static PFNGLDISABLEVERTEXATTRIBARRAYPROC DisableVertexAttribArray;
	static PFNGLENABLEVERTEXATTRIBARRAYPROC EnableVertexAttribArray;
	static PFNGLGETACTIVEATTRIBPROC GetActiveAttrib;
	static PFNGLGETACTIVEUNIFORMPROC GetActiveUniform;
	static PFNGLGETATTACHEDSHADERSPROC GetAttachedShaders;
	static PFNGLGETATTRIBLOCATIONPROC GetAttribLocation;
	static PFNGLGETPROGRAMIVPROC GetProgramiv;
	static PFNGLGETPROGRAMINFOLOGPROC GetProgramInfoLog;
	static PFNGLGETSHADERIVPROC GetShaderiv;
	static PFNGLGETSHADERINFOLOGPROC GetShaderInfoLog;
	static PFNGLGETSHADERSOURCEPROC GetShaderSource;
	static PFNGLGETUNIFORMLOCATIONPROC GetUniformLocation;
	static PFNGLGETUNIFORMFVPROC GetUniformfv;
	static PFNGLGETUNIFORMIVPROC GetUniformiv;
	static PFNGLGETVERTEXATTRIBDVPROC GetVertexAttribdv;
	static PFNGLGETVERTEXATTRIBFVPROC GetVertexAttribfv;
	static PFNGLGETVERTEXATTRIBIVPROC GetVertexAttribiv;
	static PFNGLGETVERTEXATTRIBPOINTERVPROC GetVertexAttribPointerv;
	static PFNGLISPROGRAMPROC IsProgram;
	static PFNGLISSHADERPROC IsShader;
	static PFNGLLINKPROGRAMPROC LinkProgram;
	static PFNGLSHADERSOURCEPROC ShaderSource;
	static PFNGLUSEPROGRAMPROC UseProgram;
	static PFNGLUNIFORM1FPROC Uniform1f;
	static PFNGLUNIFORM2FPROC Uniform2f;
	static PFNGLUNIFORM3FPROC Uniform3f;
	static PFNGLUNIFORM4FPROC Uniform4f;
	static PFNGLUNIFORM1IPROC Uniform1i;
	static PFNGLUNIFORM2IPROC Uniform2i;
	static PFNGLUNIFORM3IPROC Uniform3i;
	static PFNGLUNIFORM4IPROC Uniform4i;
	static PFNGLUNIFORM1FVPROC Uniform1fv;
	static PFNGLUNIFORM2FVPROC Uniform2fv;
	static PFNGLUNIFORM3FVPROC Uniform3fv;
	static PFNGLUNIFORM4FVPROC Uniform4fv;
	static PFNGLUNIFORM1IVPROC Uniform1iv;
	static PFNGLUNIFORM2IVPROC Uniform2iv;
	static PFNGLUNIFORM3IVPROC Uniform3iv;
	static PFNGLUNIFORM4IVPROC Uniform4iv;
	static PFNGLUNIFORMMATRIX2FVPROC UniformMatrix2fv;
	static PFNGLUNIFORMMATRIX3FVPROC UniformMatrix3fv;
	static PFNGLUNIFORMMATRIX4FVPROC UniformMatrix4fv;
	static PFNGLVALIDATEPROGRAMPROC ValidateProgram;
	static PFNGLVERTEXATTRIB1DPROC VertexAttrib1d;
	static PFNGLVERTEXATTRIB1DVPROC VertexAttrib1dv;
	static PFNGLVERTEXATTRIB1FPROC VertexAttrib1f;
	static PFNGLVERTEXATTRIB1FVPROC VertexAttrib1fv;
	static PFNGLVERTEXATTRIB1SPROC VertexAttrib1s;
	static PFNGLVERTEXATTRIB1SVPROC VertexAttrib1sv;
	static PFNGLVERTEXATTRIB2DPROC VertexAttrib2d;
	static PFNGLVERTEXATTRIB2DVPROC VertexAttrib2dv;
	static PFNGLVERTEXATTRIB2FPROC VertexAttrib2f;
	static PFNGLVERTEXATTRIB2FVPROC VertexAttrib2fv;
	static PFNGLVERTEXATTRIB2SPROC VertexAttrib2s;
	static PFNGLVERTEXATTRIB2SVPROC VertexAttrib2sv;
	static PFNGLVERTEXATTRIB3DPROC VertexAttrib3d;
	static PFNGLVERTEXATTRIB3DVPROC VertexAttrib3dv;
	static PFNGLVERTEXATTRIB3FPROC VertexAttrib3f;
	static PFNGLVERTEXATTRIB3FVPROC VertexAttrib3fv;
	static PFNGLVERTEXATTRIB3SPROC VertexAttrib3s;
	static PFNGLVERTEXATTRIB3SVPROC VertexAttrib3sv;
	static PFNGLVERTEXATTRIB4NBVPROC VertexAttrib4Nbv;
	static PFNGLVERTEXATTRIB4NIVPROC VertexAttrib4Niv;
	static PFNGLVERTEXATTRIB4NSVPROC VertexAttrib4Nsv;
	static PFNGLVERTEXATTRIB4NUBPROC VertexAttrib4Nub;
	static PFNGLVERTEXATTRIB4NUBVPROC VertexAttrib4Nubv;
	static PFNGLVERTEXATTRIB4NUIVPROC VertexAttrib4Nuiv;
	static PFNGLVERTEXATTRIB4NUSVPROC VertexAttrib4Nusv;
	static PFNGLVERTEXATTRIB4BVPROC VertexAttrib4bv;
	static PFNGLVERTEXATTRIB4DPROC VertexAttrib4d;
	static PFNGLVERTEXATTRIB4DVPROC VertexAttrib4dv;
	static PFNGLVERTEXATTRIB4FPROC VertexAttrib4f;
	static PFNGLVERTEXATTRIB4FVPROC VertexAttrib4fv;
	static PFNGLVERTEXATTRIB4IVPROC VertexAttrib4iv;
	static PFNGLVERTEXATTRIB4SPROC VertexAttrib4s;
	static PFNGLVERTEXATTRIB4SVPROC VertexAttrib4sv;
	static PFNGLVERTEXATTRIB4UBVPROC VertexAttrib4ubv;
	static PFNGLVERTEXATTRIB4UIVPROC VertexAttrib4uiv;
	static PFNGLVERTEXATTRIB4USVPROC VertexAttrib4usv;
	static PFNGLVERTEXATTRIBPOINTERPROC VertexAttribPointer;
	static PFNGLUNIFORMMATRIX2X3FVPROC UniformMatrix2x3fv;
	static PFNGLUNIFORMMATRIX3X2FVPROC UniformMatrix3x2fv;
	static PFNGLUNIFORMMATRIX2X4FVPROC UniformMatrix2x4fv;
	static PFNGLUNIFORMMATRIX4X2FVPROC UniformMatrix4x2fv;
	static PFNGLUNIFORMMATRIX3X4FVPROC UniformMatrix3x4fv;
	static PFNGLUNIFORMMATRIX4X3FVPROC UniformMatrix4x3fv;
	static PFNGLCOLORMASKIPROC ColorMaski;
	static PFNGLGETBOOLEANI_VPROC GetBooleani_v;
	static PFNGLGETINTEGERI_VPROC GetIntegeri_v;
	static PFNGLENABLEIPROC Enablei;
	static PFNGLDISABLEIPROC Disablei;
	static PFNGLISENABLEDIPROC IsEnabledi;
	static PFNGLBEGINTRANSFORMFEEDBACKPROC BeginTransformFeedback;
	static PFNGLENDTRANSFORMFEEDBACKPROC EndTransformFeedback;
	static PFNGLBINDBUFFERRANGEPROC BindBufferRange;
	static PFNGLBINDBUFFERBASEPROC BindBufferBase;
	static PFNGLTRANSFORMFEEDBACKVARYINGSPROC TransformFeedbackVaryings;
	static PFNGLGETTRANSFORMFEEDBACKVARYINGPROC GetTransformFeedbackVarying;
	static PFNGLCLAMPCOLORPROC ClampColor;
	static PFNGLBEGINCONDITIONALRENDERPROC BeginConditionalRender;
	static PFNGLENDCONDITIONALRENDERPROC EndConditionalRender;
	static PFNGLVERTEXATTRIBIPOINTERPROC VertexAttribIPointer;
	static PFNGLGETVERTEXATTRIBIIVPROC GetVertexAttribIiv;
	static PFNGLGETVERTEXATTRIBIUIVPROC GetVertexAttribIuiv;
	static PFNGLVERTEXATTRIBI1IPROC VertexAttribI1i;
	static PFNGLVERTEXATTRIBI2IPROC VertexAttribI2i;
	static PFNGLVERTEXATTRIBI3IPROC VertexAttribI3i;
	static PFNGLVERTEXATTRIBI4IPROC VertexAttribI4i;
	static PFNGLVERTEXATTRIBI1UIPROC VertexAttribI1ui;
	static PFNGLVERTEXATTRIBI2UIPROC VertexAttribI2ui;
	static PFNGLVERTEXATTRIBI3UIPROC VertexAttribI3ui;
	static PFNGLVERTEXATTRIBI4UIPROC VertexAttribI4ui;
	static PFNGLVERTEXATTRIBI1IVPROC VertexAttribI1iv;
	static PFNGLVERTEXATTRIBI2IVPROC VertexAttribI2iv;
	static PFNGLVERTEXATTRIBI3IVPROC VertexAttribI3iv;
	static PFNGLVERTEXATTRIBI4IVPROC VertexAttribI4iv;
	static PFNGLVERTEXATTRIBI1UIVPROC VertexAttribI1uiv;
	static PFNGLVERTEXATTRIBI2UIVPROC VertexAttribI2uiv;
	static PFNGLVERTEXATTRIBI3UIVPROC VertexAttribI3uiv;
	static PFNGLVERTEXATTRIBI4UIVPROC VertexAttribI4uiv;
	static PFNGLVERTEXATTRIBI4BVPROC VertexAttribI4bv;
	static PFNGLVERTEXATTRIBI4SVPROC VertexAttribI4sv;
	static PFNGLVERTEXATTRIBI4UBVPROC VertexAttribI4ubv;
	static PFNGLVERTEXATTRIBI4USVPROC VertexAttribI4usv;
	static PFNGLGETUNIFORMUIVPROC GetUniformuiv;
	static PFNGLBINDFRAGDATALOCATIONPROC BindFragDataLocation;
	static PFNGLGETFRAGDATALOCATIONPROC GetFragDataLocation;
	static PFNGLUNIFORM1UIPROC Uniform1ui;
	static PFNGLUNIFORM2UIPROC Uniform2ui;
	static PFNGLUNIFORM3UIPROC Uniform3ui;
	static PFNGLUNIFORM4UIPROC Uniform4ui;
	static PFNGLUNIFORM1UIVPROC Uniform1uiv;
	static PFNGLUNIFORM2UIVPROC Uniform2uiv;
	static PFNGLUNIFORM3UIVPROC Uniform3uiv;
	static PFNGLUNIFORM4UIVPROC Uniform4uiv;
	static PFNGLTEXPARAMETERIIVPROC TexParameterIiv;
	static PFNGLTEXPARAMETERIUIVPROC TexParameterIuiv;
	static PFNGLGETTEXPARAMETERIIVPROC GetTexParameterIiv;
	static PFNGLGETTEXPARAMETERIUIVPROC GetTexParameterIuiv;
	static PFNGLCLEARBUFFERIVPROC ClearBufferiv;
	static PFNGLCLEARBUFFERUIVPROC ClearBufferuiv;
	static PFNGLCLEARBUFFERFVPROC ClearBufferfv;
	static PFNGLCLEARBUFFERFIPROC ClearBufferfi;
	static PFNGLGETSTRINGIPROC GetStringi;
	static PFNGLDRAWARRAYSINSTANCEDPROC DrawArraysInstanced;
	static PFNGLDRAWELEMENTSINSTANCEDPROC DrawElementsInstanced;
	static PFNGLTEXBUFFERPROC TexBuffer;
	static PFNGLPRIMITIVERESTARTINDEXPROC PrimitiveRestartIndex;
	static PFNGLGETINTEGER64I_VPROC GetInteger64i_v;
	static PFNGLGETBUFFERPARAMETERI64VPROC GetBufferParameteri64v;
	static PFNGLFRAMEBUFFERTEXTUREPROC FramebufferTexture;
	static PFNGLVERTEXATTRIBDIVISORPROC VertexAttribDivisor;
	static PFNGLMINSAMPLESHADINGPROC MinSampleShading;
	static PFNGLBLENDEQUATIONIPROC BlendEquationi;
	static PFNGLBLENDEQUATIONSEPARATEIPROC BlendEquationSeparatei;
	static PFNGLBLENDFUNCIPROC BlendFunci;
	static PFNGLBLENDFUNCSEPARATEIPROC BlendFuncSeparatei;
	static PFNGLISRENDERBUFFERPROC IsRenderbuffer;
	static PFNGLBINDRENDERBUFFERPROC BindRenderbuffer;
	static PFNGLDELETERENDERBUFFERSPROC DeleteRenderbuffers;
	static PFNGLGENRENDERBUFFERSPROC GenRenderbuffers;
	static PFNGLRENDERBUFFERSTORAGEPROC RenderbufferStorage;
	static PFNGLGETRENDERBUFFERPARAMETERIVPROC GetRenderbufferParameteriv;
	static PFNGLISFRAMEBUFFERPROC IsFramebuffer;
	static PFNGLBINDFRAMEBUFFERPROC BindFramebuffer;
	static PFNGLDELETEFRAMEBUFFERSPROC DeleteFramebuffers;
	static PFNGLGENFRAMEBUFFERSPROC GenFramebuffers;
	static PFNGLCHECKFRAMEBUFFERSTATUSPROC CheckFramebufferStatus;
	static PFNGLFRAMEBUFFERTEXTURE1DPROC FramebufferTexture1D;
	static PFNGLFRAMEBUFFERTEXTURE2DPROC FramebufferTexture2D;
	static PFNGLFRAMEBUFFERTEXTURE3DPROC FramebufferTexture3D;
	static PFNGLFRAMEBUFFERRENDERBUFFERPROC FramebufferRenderbuffer;
	static PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC GetFramebufferAttachmentParameteriv;
	static PFNGLGENERATEMIPMAPPROC GenerateMipmap;
	static PFNGLBLITFRAMEBUFFERPROC BlitFramebuffer;
	static PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC RenderbufferStorageMultisample;
	static PFNGLFRAMEBUFFERTEXTURELAYERPROC FramebufferTextureLayer;
	static PFNGLMAPBUFFERRANGEPROC MapBufferRange;
	static PFNGLFLUSHMAPPEDBUFFERRANGEPROC FlushMappedBufferRange;
	static PFNGLBINDVERTEXARRAYPROC BindVertexArray;
	static PFNGLDELETEVERTEXARRAYSPROC DeleteVertexArrays;
	static PFNGLGENVERTEXARRAYSPROC GenVertexArrays;
	static PFNGLISVERTEXARRAYPROC IsVertexArray;
	static PFNGLGETUNIFORMINDICESPROC GetUniformIndices;
	static PFNGLGETACTIVEUNIFORMSIVPROC GetActiveUniformsiv;
	static PFNGLGETACTIVEUNIFORMNAMEPROC GetActiveUniformName;
	static PFNGLGETUNIFORMBLOCKINDEXPROC GetUniformBlockIndex;
	static PFNGLGETACTIVEUNIFORMBLOCKIVPROC GetActiveUniformBlockiv;
	static PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC GetActiveUniformBlockName;
	static PFNGLUNIFORMBLOCKBINDINGPROC UniformBlockBinding;
	static PFNGLCOPYBUFFERSUBDATAPROC CopyBufferSubData;
	static PFNGLDRAWELEMENTSBASEVERTEXPROC DrawElementsBaseVertex;
	static PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC DrawRangeElementsBaseVertex;
	static PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC DrawElementsInstancedBaseVertex;
	static PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC MultiDrawElementsBaseVertex;
	static PFNGLPROVOKINGVERTEXPROC ProvokingVertex;
	static PFNGLFENCESYNCPROC FenceSync;
	static PFNGLISSYNCPROC IsSync;
	static PFNGLDELETESYNCPROC DeleteSync;
	static PFNGLCLIENTWAITSYNCPROC ClientWaitSync;
	static PFNGLWAITSYNCPROC WaitSync;
	static PFNGLGETINTEGER64VPROC GetInteger64v;
	static PFNGLGETSYNCIVPROC GetSynciv;
	static PFNGLTEXIMAGE2DMULTISAMPLEPROC TexImage2DMultisample;
	static PFNGLTEXIMAGE3DMULTISAMPLEPROC TexImage3DMultisample;
	static PFNGLGETMULTISAMPLEFVPROC GetMultisamplefv;
	static PFNGLSAMPLEMASKIPROC SampleMaski;
	static PFNGLBLENDEQUATIONIARBPROC BlendEquationiARB;
	static PFNGLBLENDEQUATIONSEPARATEIARBPROC BlendEquationSeparateiARB;
	static PFNGLBLENDFUNCIARBPROC BlendFunciARB;
	static PFNGLBLENDFUNCSEPARATEIARBPROC BlendFuncSeparateiARB;
	static PFNGLMINSAMPLESHADINGARBPROC MinSampleShadingARB;
	static PFNGLNAMEDSTRINGARBPROC NamedStringARB;
	static PFNGLDELETENAMEDSTRINGARBPROC DeleteNamedStringARB;
	static PFNGLCOMPILESHADERINCLUDEARBPROC CompileShaderIncludeARB;
	static PFNGLISNAMEDSTRINGARBPROC IsNamedStringARB;
	static PFNGLGETNAMEDSTRINGARBPROC GetNamedStringARB;
	static PFNGLGETNAMEDSTRINGIVARBPROC GetNamedStringivARB;
	static PFNGLBINDFRAGDATALOCATIONINDEXEDPROC BindFragDataLocationIndexed;
	static PFNGLGETFRAGDATAINDEXPROC GetFragDataIndex;
	static PFNGLGENSAMPLERSPROC GenSamplers;
	static PFNGLDELETESAMPLERSPROC DeleteSamplers;
	static PFNGLISSAMPLERPROC IsSampler;
	static PFNGLBINDSAMPLERPROC BindSampler;
	static PFNGLSAMPLERPARAMETERIPROC SamplerParameteri;
	static PFNGLSAMPLERPARAMETERIVPROC SamplerParameteriv;
	static PFNGLSAMPLERPARAMETERFPROC SamplerParameterf;
	static PFNGLSAMPLERPARAMETERFVPROC SamplerParameterfv;
	static PFNGLSAMPLERPARAMETERIIVPROC SamplerParameterIiv;
	static PFNGLSAMPLERPARAMETERIUIVPROC SamplerParameterIuiv;
	static PFNGLGETSAMPLERPARAMETERIVPROC GetSamplerParameteriv;
	static PFNGLGETSAMPLERPARAMETERIIVPROC GetSamplerParameterIiv;
	static PFNGLGETSAMPLERPARAMETERFVPROC GetSamplerParameterfv;
	static PFNGLGETSAMPLERPARAMETERIUIVPROC GetSamplerParameterIuiv;
	static PFNGLQUERYCOUNTERPROC QueryCounter;
	static PFNGLGETQUERYOBJECTI64VPROC GetQueryObjecti64v;
	static PFNGLGETQUERYOBJECTUI64VPROC GetQueryObjectui64v;
	static PFNGLVERTEXP2UIPROC VertexP2ui;
	static PFNGLVERTEXP2UIVPROC VertexP2uiv;
	static PFNGLVERTEXP3UIPROC VertexP3ui;
	static PFNGLVERTEXP3UIVPROC VertexP3uiv;
	static PFNGLVERTEXP4UIPROC VertexP4ui;
	static PFNGLVERTEXP4UIVPROC VertexP4uiv;
	static PFNGLTEXCOORDP1UIPROC TexCoordP1ui;
	static PFNGLTEXCOORDP1UIVPROC TexCoordP1uiv;
	static PFNGLTEXCOORDP2UIPROC TexCoordP2ui;
	static PFNGLTEXCOORDP2UIVPROC TexCoordP2uiv;
	static PFNGLTEXCOORDP3UIPROC TexCoordP3ui;
	static PFNGLTEXCOORDP3UIVPROC TexCoordP3uiv;
	static PFNGLTEXCOORDP4UIPROC TexCoordP4ui;
	static PFNGLTEXCOORDP4UIVPROC TexCoordP4uiv;
	static PFNGLMULTITEXCOORDP1UIPROC MultiTexCoordP1ui;
	static PFNGLMULTITEXCOORDP1UIVPROC MultiTexCoordP1uiv;
	static PFNGLMULTITEXCOORDP2UIPROC MultiTexCoordP2ui;
	static PFNGLMULTITEXCOORDP2UIVPROC MultiTexCoordP2uiv;
	static PFNGLMULTITEXCOORDP3UIPROC MultiTexCoordP3ui;
	static PFNGLMULTITEXCOORDP3UIVPROC MultiTexCoordP3uiv;
	static PFNGLMULTITEXCOORDP4UIPROC MultiTexCoordP4ui;
	static PFNGLMULTITEXCOORDP4UIVPROC MultiTexCoordP4uiv;
	static PFNGLNORMALP3UIPROC NormalP3ui;
	static PFNGLNORMALP3UIVPROC NormalP3uiv;
	static PFNGLCOLORP3UIPROC ColorP3ui;
	static PFNGLCOLORP3UIVPROC ColorP3uiv;
	static PFNGLCOLORP4UIPROC ColorP4ui;
	static PFNGLCOLORP4UIVPROC ColorP4uiv;
	static PFNGLSECONDARYCOLORP3UIPROC SecondaryColorP3ui;
	static PFNGLSECONDARYCOLORP3UIVPROC SecondaryColorP3uiv;
	static PFNGLVERTEXATTRIBP1UIPROC VertexAttribP1ui;
	static PFNGLVERTEXATTRIBP1UIVPROC VertexAttribP1uiv;
	static PFNGLVERTEXATTRIBP2UIPROC VertexAttribP2ui;
	static PFNGLVERTEXATTRIBP2UIVPROC VertexAttribP2uiv;
	static PFNGLVERTEXATTRIBP3UIPROC VertexAttribP3ui;
	static PFNGLVERTEXATTRIBP3UIVPROC VertexAttribP3uiv;
	static PFNGLVERTEXATTRIBP4UIPROC VertexAttribP4ui;
	static PFNGLVERTEXATTRIBP4UIVPROC VertexAttribP4uiv;
	static PFNGLDRAWARRAYSINDIRECTPROC DrawArraysIndirect;
	static PFNGLDRAWELEMENTSINDIRECTPROC DrawElementsIndirect;
	static PFNGLUNIFORM1DPROC Uniform1d;
	static PFNGLUNIFORM2DPROC Uniform2d;
	static PFNGLUNIFORM3DPROC Uniform3d;
	static PFNGLUNIFORM4DPROC Uniform4d;
	static PFNGLUNIFORM1DVPROC Uniform1dv;
	static PFNGLUNIFORM2DVPROC Uniform2dv;
	static PFNGLUNIFORM3DVPROC Uniform3dv;
	static PFNGLUNIFORM4DVPROC Uniform4dv;
	static PFNGLUNIFORMMATRIX2DVPROC UniformMatrix2dv;
	static PFNGLUNIFORMMATRIX3DVPROC UniformMatrix3dv;
	static PFNGLUNIFORMMATRIX4DVPROC UniformMatrix4dv;
	static PFNGLUNIFORMMATRIX2X3DVPROC UniformMatrix2x3dv;
	static PFNGLUNIFORMMATRIX2X4DVPROC UniformMatrix2x4dv;
	static PFNGLUNIFORMMATRIX3X2DVPROC UniformMatrix3x2dv;
	static PFNGLUNIFORMMATRIX3X4DVPROC UniformMatrix3x4dv;
	static PFNGLUNIFORMMATRIX4X2DVPROC UniformMatrix4x2dv;
	static PFNGLUNIFORMMATRIX4X3DVPROC UniformMatrix4x3dv;
	static PFNGLGETUNIFORMDVPROC GetUniformdv;
	static PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC GetSubroutineUniformLocation;
	static PFNGLGETSUBROUTINEINDEXPROC GetSubroutineIndex;
	static PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC GetActiveSubroutineUniformiv;
	static PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC GetActiveSubroutineUniformName;
	static PFNGLGETACTIVESUBROUTINENAMEPROC GetActiveSubroutineName;
	static PFNGLUNIFORMSUBROUTINESUIVPROC UniformSubroutinesuiv;
	static PFNGLGETUNIFORMSUBROUTINEUIVPROC GetUniformSubroutineuiv;
	static PFNGLGETPROGRAMSTAGEIVPROC GetProgramStageiv;
	static PFNGLPATCHPARAMETERIPROC PatchParameteri;
	static PFNGLPATCHPARAMETERFVPROC PatchParameterfv;
	static PFNGLBINDTRANSFORMFEEDBACKPROC BindTransformFeedback;
	static PFNGLDELETETRANSFORMFEEDBACKSPROC DeleteTransformFeedbacks;
	static PFNGLGENTRANSFORMFEEDBACKSPROC GenTransformFeedbacks;
	static PFNGLISTRANSFORMFEEDBACKPROC IsTransformFeedback;
	static PFNGLPAUSETRANSFORMFEEDBACKPROC PauseTransformFeedback;
	static PFNGLRESUMETRANSFORMFEEDBACKPROC ResumeTransformFeedback;
	static PFNGLDRAWTRANSFORMFEEDBACKPROC DrawTransformFeedback;
	static PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC DrawTransformFeedbackStream;
	static PFNGLBEGINQUERYINDEXEDPROC BeginQueryIndexed;
	static PFNGLENDQUERYINDEXEDPROC EndQueryIndexed;
	static PFNGLGETQUERYINDEXEDIVPROC GetQueryIndexediv;
	static PFNGLRELEASESHADERCOMPILERPROC ReleaseShaderCompiler;
	static PFNGLSHADERBINARYPROC ShaderBinary;
	static PFNGLGETSHADERPRECISIONFORMATPROC GetShaderPrecisionFormat;
	static PFNGLDEPTHRANGEFPROC DepthRangef;
	static PFNGLCLEARDEPTHFPROC ClearDepthf;
	static PFNGLGETPROGRAMBINARYPROC GetProgramBinary;
	static PFNGLPROGRAMBINARYPROC ProgramBinary;
	static PFNGLPROGRAMPARAMETERIPROC ProgramParameteri;
	static PFNGLUSEPROGRAMSTAGESPROC UseProgramStages;
	static PFNGLACTIVESHADERPROGRAMPROC ActiveShaderProgram;
	static PFNGLCREATESHADERPROGRAMVPROC CreateShaderProgramv;
	static PFNGLBINDPROGRAMPIPELINEPROC BindProgramPipeline;
	static PFNGLDELETEPROGRAMPIPELINESPROC DeleteProgramPipelines;
	static PFNGLGENPROGRAMPIPELINESPROC GenProgramPipelines;
	static PFNGLISPROGRAMPIPELINEPROC IsProgramPipeline;
	static PFNGLGETPROGRAMPIPELINEIVPROC GetProgramPipelineiv;
	static PFNGLPROGRAMUNIFORM1IPROC ProgramUniform1i;
	static PFNGLPROGRAMUNIFORM1IVPROC ProgramUniform1iv;
	static PFNGLPROGRAMUNIFORM1FPROC ProgramUniform1f;
	static PFNGLPROGRAMUNIFORM1FVPROC ProgramUniform1fv;
	static PFNGLPROGRAMUNIFORM1DPROC ProgramUniform1d;
	static PFNGLPROGRAMUNIFORM1DVPROC ProgramUniform1dv;
	static PFNGLPROGRAMUNIFORM1UIPROC ProgramUniform1ui;
	static PFNGLPROGRAMUNIFORM1UIVPROC ProgramUniform1uiv;
	static PFNGLPROGRAMUNIFORM2IPROC ProgramUniform2i;
	static PFNGLPROGRAMUNIFORM2IVPROC ProgramUniform2iv;
	static PFNGLPROGRAMUNIFORM2FPROC ProgramUniform2f;
	static PFNGLPROGRAMUNIFORM2FVPROC ProgramUniform2fv;
	static PFNGLPROGRAMUNIFORM2DPROC ProgramUniform2d;
	static PFNGLPROGRAMUNIFORM2DVPROC ProgramUniform2dv;
	static PFNGLPROGRAMUNIFORM2UIPROC ProgramUniform2ui;
	static PFNGLPROGRAMUNIFORM2UIVPROC ProgramUniform2uiv;
	static PFNGLPROGRAMUNIFORM3IPROC ProgramUniform3i;
	static PFNGLPROGRAMUNIFORM3IVPROC ProgramUniform3iv;
	static PFNGLPROGRAMUNIFORM3FPROC ProgramUniform3f;
	static PFNGLPROGRAMUNIFORM3FVPROC ProgramUniform3fv;
	static PFNGLPROGRAMUNIFORM3DPROC ProgramUniform3d;
	static PFNGLPROGRAMUNIFORM3DVPROC ProgramUniform3dv;
	static PFNGLPROGRAMUNIFORM3UIPROC ProgramUniform3ui;
	static PFNGLPROGRAMUNIFORM3UIVPROC ProgramUniform3uiv;
	static PFNGLPROGRAMUNIFORM4IPROC ProgramUniform4i;
	static PFNGLPROGRAMUNIFORM4IVPROC ProgramUniform4iv;
	static PFNGLPROGRAMUNIFORM4FPROC ProgramUniform4f;
	static PFNGLPROGRAMUNIFORM4FVPROC ProgramUniform4fv;
	static PFNGLPROGRAMUNIFORM4DPROC ProgramUniform4d;
	static PFNGLPROGRAMUNIFORM4DVPROC ProgramUniform4dv;
	static PFNGLPROGRAMUNIFORM4UIPROC ProgramUniform4ui;
	static PFNGLPROGRAMUNIFORM4UIVPROC ProgramUniform4uiv;
	static PFNGLPROGRAMUNIFORMMATRIX2FVPROC ProgramUniformMatrix2fv;
	static PFNGLPROGRAMUNIFORMMATRIX3FVPROC ProgramUniformMatrix3fv;
	static PFNGLPROGRAMUNIFORMMATRIX4FVPROC ProgramUniformMatrix4fv;
	static PFNGLPROGRAMUNIFORMMATRIX2DVPROC ProgramUniformMatrix2dv;
	static PFNGLPROGRAMUNIFORMMATRIX3DVPROC ProgramUniformMatrix3dv;
	static PFNGLPROGRAMUNIFORMMATRIX4DVPROC ProgramUniformMatrix4dv;
	static PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC ProgramUniformMatrix2x3fv;
	static PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC ProgramUniformMatrix3x2fv;
	static PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC ProgramUniformMatrix2x4fv;
	static PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC ProgramUniformMatrix4x2fv;
	static PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC ProgramUniformMatrix3x4fv;
	static PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC ProgramUniformMatrix4x3fv;
	static PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC ProgramUniformMatrix2x3dv;
	static PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC ProgramUniformMatrix3x2dv;
	static PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC ProgramUniformMatrix2x4dv;
	static PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC ProgramUniformMatrix4x2dv;
	static PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC ProgramUniformMatrix3x4dv;
	static PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC ProgramUniformMatrix4x3dv;
	static PFNGLVALIDATEPROGRAMPIPELINEPROC ValidateProgramPipeline;
	static PFNGLGETPROGRAMPIPELINEINFOLOGPROC GetProgramPipelineInfoLog;
	static PFNGLVERTEXATTRIBL1DPROC VertexAttribL1d;
	static PFNGLVERTEXATTRIBL2DPROC VertexAttribL2d;
	static PFNGLVERTEXATTRIBL3DPROC VertexAttribL3d;
	static PFNGLVERTEXATTRIBL4DPROC VertexAttribL4d;
	static PFNGLVERTEXATTRIBL1DVPROC VertexAttribL1dv;
	static PFNGLVERTEXATTRIBL2DVPROC VertexAttribL2dv;
	static PFNGLVERTEXATTRIBL3DVPROC VertexAttribL3dv;
	static PFNGLVERTEXATTRIBL4DVPROC VertexAttribL4dv;
	static PFNGLVERTEXATTRIBLPOINTERPROC VertexAttribLPointer;
	static PFNGLGETVERTEXATTRIBLDVPROC GetVertexAttribLdv;
	static PFNGLVIEWPORTARRAYVPROC ViewportArrayv;
	static PFNGLVIEWPORTINDEXEDFPROC ViewportIndexedf;
	static PFNGLVIEWPORTINDEXEDFVPROC ViewportIndexedfv;
	static PFNGLSCISSORARRAYVPROC ScissorArrayv;
	static PFNGLSCISSORINDEXEDPROC ScissorIndexed;
	static PFNGLSCISSORINDEXEDVPROC ScissorIndexedv;
	static PFNGLDEPTHRANGEARRAYVPROC DepthRangeArrayv;
	static PFNGLDEPTHRANGEINDEXEDPROC DepthRangeIndexed;
	static PFNGLGETFLOATI_VPROC GetFloati_v;
	static PFNGLGETDOUBLEI_VPROC GetDoublei_v;
	static PFNGLCREATESYNCFROMCLEVENTARBPROC CreateSyncFromCLeventARB;
	static PFNGLDEBUGMESSAGECONTROLARBPROC DebugMessageControlARB;
	static PFNGLDEBUGMESSAGEINSERTARBPROC DebugMessageInsertARB;
	static PFNGLDEBUGMESSAGECALLBACKARBPROC DebugMessageCallbackARB;
	static PFNGLGETDEBUGMESSAGELOGARBPROC GetDebugMessageLogARB;
	static PFNGLGETGRAPHICSRESETSTATUSARBPROC GetGraphicsResetStatusARB;
	static PFNGLGETNTEXIMAGEARBPROC GetnTexImageARB;
	static PFNGLREADNPIXELSARBPROC ReadnPixelsARB;
	static PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC GetnCompressedTexImageARB;
	static PFNGLGETNUNIFORMFVARBPROC GetnUniformfvARB;
	static PFNGLGETNUNIFORMIVARBPROC GetnUniformivARB;
	static PFNGLGETNUNIFORMUIVARBPROC GetnUniformuivARB;
	static PFNGLGETNUNIFORMDVARBPROC GetnUniformdvARB;
	static PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC DrawArraysInstancedBaseInstance;
	static PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC DrawElementsInstancedBaseInstance;
	static PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC DrawElementsInstancedBaseVertexBaseInstance;
	static PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC DrawTransformFeedbackInstanced;
	static PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC DrawTransformFeedbackStreamInstanced;
	static PFNGLGETINTERNALFORMATIVPROC GetInternalformativ;
	static PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC GetActiveAtomicCounterBufferiv;
	static PFNGLBINDIMAGETEXTUREPROC BindImageTexture;
	static PFNGLMEMORYBARRIERPROC MemoryBarrier;
	static PFNGLTEXSTORAGE1DPROC TexStorage1D;
	static PFNGLTEXSTORAGE2DPROC TexStorage2D;
	static PFNGLTEXSTORAGE3DPROC TexStorage3D;
	static PFNGLTEXTURESTORAGE1DEXTPROC TextureStorage1DEXT;
	static PFNGLTEXTURESTORAGE2DEXTPROC TextureStorage2DEXT;
	static PFNGLTEXTURESTORAGE3DEXTPROC TextureStorage3DEXT;
	static PFNGLDEBUGMESSAGECONTROLPROC DebugMessageControl;
	static PFNGLDEBUGMESSAGEINSERTPROC DebugMessageInsert;
	static PFNGLDEBUGMESSAGECALLBACKPROC DebugMessageCallback;
	static PFNGLGETDEBUGMESSAGELOGPROC GetDebugMessageLog;
	static PFNGLPUSHDEBUGGROUPPROC PushDebugGroup;
	static PFNGLPOPDEBUGGROUPPROC PopDebugGroup;
	static PFNGLOBJECTLABELPROC ObjectLabel;
	static PFNGLGETOBJECTLABELPROC GetObjectLabel;
	static PFNGLOBJECTPTRLABELPROC ObjectPtrLabel;
	static PFNGLGETOBJECTPTRLABELPROC GetObjectPtrLabel;
	static PFNGLCLEARBUFFERDATAPROC ClearBufferData;
	static PFNGLCLEARBUFFERSUBDATAPROC ClearBufferSubData;
	static PFNGLCLEARNAMEDBUFFERDATAEXTPROC ClearNamedBufferDataEXT;
	static PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC ClearNamedBufferSubDataEXT;
	static PFNGLDISPATCHCOMPUTEPROC DispatchCompute;
	static PFNGLDISPATCHCOMPUTEINDIRECTPROC DispatchComputeIndirect;
	static PFNGLCOPYIMAGESUBDATAPROC CopyImageSubData;
	static PFNGLTEXTUREVIEWPROC TextureView;
	static PFNGLBINDVERTEXBUFFERPROC BindVertexBuffer;
	static PFNGLVERTEXATTRIBFORMATPROC VertexAttribFormat;
	static PFNGLVERTEXATTRIBIFORMATPROC VertexAttribIFormat;
	static PFNGLVERTEXATTRIBLFORMATPROC VertexAttribLFormat;
	static PFNGLVERTEXATTRIBBINDINGPROC VertexAttribBinding;
	static PFNGLVERTEXBINDINGDIVISORPROC VertexBindingDivisor;
	static PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC VertexArrayBindVertexBufferEXT;
	static PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC VertexArrayVertexAttribFormatEXT;
	static PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC VertexArrayVertexAttribIFormatEXT;
	static PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC VertexArrayVertexAttribLFormatEXT;
	static PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC VertexArrayVertexAttribBindingEXT;
	static PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC VertexArrayVertexBindingDivisorEXT;
	static PFNGLFRAMEBUFFERPARAMETERIPROC FramebufferParameteri;
	static PFNGLGETFRAMEBUFFERPARAMETERIVPROC GetFramebufferParameteriv;
	static PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC NamedFramebufferParameteriEXT;
	static PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC GetNamedFramebufferParameterivEXT;
	static PFNGLGETINTERNALFORMATI64VPROC GetInternalformati64v;
	static PFNGLINVALIDATETEXSUBIMAGEPROC InvalidateTexSubImage;
	static PFNGLINVALIDATETEXIMAGEPROC InvalidateTexImage;
	static PFNGLINVALIDATEBUFFERSUBDATAPROC InvalidateBufferSubData;
	static PFNGLINVALIDATEBUFFERDATAPROC InvalidateBufferData;
	static PFNGLINVALIDATEFRAMEBUFFERPROC InvalidateFramebuffer;
	static PFNGLINVALIDATESUBFRAMEBUFFERPROC InvalidateSubFramebuffer;
	static PFNGLMULTIDRAWARRAYSINDIRECTPROC MultiDrawArraysIndirect;
	static PFNGLMULTIDRAWELEMENTSINDIRECTPROC MultiDrawElementsIndirect;
	static PFNGLGETPROGRAMINTERFACEIVPROC GetProgramInterfaceiv;
	static PFNGLGETPROGRAMRESOURCEINDEXPROC GetProgramResourceIndex;
	static PFNGLGETPROGRAMRESOURCENAMEPROC GetProgramResourceName;
	static PFNGLGETPROGRAMRESOURCEIVPROC GetProgramResourceiv;
	static PFNGLGETPROGRAMRESOURCELOCATIONPROC GetProgramResourceLocation;
	static PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC GetProgramResourceLocationIndex;
	static PFNGLSHADERSTORAGEBLOCKBINDINGPROC ShaderStorageBlockBinding;
	static PFNGLTEXBUFFERRANGEPROC TexBufferRange;
	static PFNGLTEXTUREBUFFERRANGEEXTPROC TextureBufferRangeEXT;
	static PFNGLTEXSTORAGE2DMULTISAMPLEPROC TexStorage2DMultisample;
	static PFNGLTEXSTORAGE3DMULTISAMPLEPROC TexStorage3DMultisample;
	static PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC TextureStorage2DMultisampleEXT;
	static PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC TextureStorage3DMultisampleEXT;


};
#endif
