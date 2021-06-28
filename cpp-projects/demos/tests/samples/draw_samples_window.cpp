
#include "draw_samples_window.hpp"

// std
#include <filesystem>

// imgui
#include "imgui/extra/imgui_markdown.h"

// base
#include "utility/benchmark.hpp"

// local
#include "imgui/imgui_utility.hpp"
#include "shaders_tests.hpp"

using namespace tool::gl;
using namespace tool::graphics;

bool DrawSampleWindow::init_shaders(){

    std::vector<Shader::Type> VS_FS         = {Shader::Type::vertex,Shader::Type::fragment};
    std::vector<Shader::Type> VS_FS_GS      = {Shader::Type::vertex,Shader::Type::fragment, Shader::Type::geometry};
    std::vector<Shader::Type> VS_FS_TES_TCS = {Shader::Type::vertex,Shader::Type::fragment, Shader::Type::tess_eval, Shader::Type::tess_control};

    //    std_v1<std::pair<std::string, std::vector<Shader::Type>*>> shadersNames={
    //        {"ch4/pbr",&VS_FS}
    //    };

    std_v1<std::pair<std::string, std::vector<Shader::Type>*>> shadersNames={
        {"others/unicolor",&VS_FS},{"others/skybox",&VS_FS},{"others/screen-quad",&VS_FS}, // ch1
        {"ch2/1",&VS_FS}, // ch2
        {"ch3/diffuse",&VS_FS},{"ch3/phong",&VS_FS},{"ch3/twoside",&VS_FS},{"ch3/flat",&VS_FS},{"ch3/discard",&VS_FS}, // ch3
        {"ch4/phong-multi-lights",&VS_FS},{"ch4/phong-directional-light",&VS_FS},{"ch4/phong-per-fragment",&VS_FS},{"ch4/blinn-phong",&VS_FS}, // ch4
        {"ch4/cartoon",&VS_FS},{"ch4/pbr",&VS_FS},
        {"ch5/scene-texture",&VS_FS},{"ch5/scene-multi-textures",&VS_FS},{"ch5/discard-pixels",&VS_FS},{"ch5/normal-map",&VS_FS}, // ch5
        {"ch5/parallax-mapping",&VS_FS},{"ch5/steep-parallax-mapping",&VS_FS},{"ch5/reflect-cubemap",&VS_FS},{"ch5/refract-cubemap",&VS_FS},
        {"ch5/projected-texture",&VS_FS},{"ch5/render-to-texture",&VS_FS},{"ch5/sampler-objects",&VS_FS},{"ch5/diffuse-image-based-lighting",&VS_FS},
        {"ch6/edge-detection-filter",&VS_FS},{"ch6/gaussian-filter",&VS_FS},{"ch6/hdr-lighting-tone-mapping",&VS_FS},{"ch6/hdr-bloom",&VS_FS}, // ch6
        {"ch6/deferred",&VS_FS},{"ch6/ssao",&VS_FS},{"ch6/oit",&VS_FS},
        {"ch7/solid",&VS_FS},{"ch7/bezcurve", &VS_FS_TES_TCS}, {"ch7/shadewire", &VS_FS_GS}, {"ch7/pointsprite", &VS_FS_GS}, // ch7
        {"ch7/silhouette", &VS_FS_GS},
        {"ch8/shadowmap", &VS_FS},{"ch8/solid", &VS_FS}, // ch8
        {"learn/3_1_1_shadow_mapping",          &VS_FS}, // learnopengl
        {"learn/3_1_1_shadow_mapping_depth",    &VS_FS},
        {"learn/3_1_1_debug_quad",              &VS_FS}
    };

    // find shaders dir path
    const auto currentPath = std::filesystem::current_path();
    const auto shadersPaths = currentPath / "resources" / "shaders" / "samples";
    for(const auto &shaderName : shadersNames){

        std::vector<std::string> paths;
        paths.reserve(shaderName.second->size());
        for(const auto &shaderType : *shaderName.second){

            switch(shaderType){
            case Shader::Type::vertex:
                paths.emplace_back((shadersPaths / (shaderName.first + ".vs")).string());
                break;
            case Shader::Type::fragment:
                paths.emplace_back((shadersPaths / (shaderName.first + ".fs")).string());
                break;
            case Shader::Type::tess_eval:
                paths.emplace_back((shadersPaths / (shaderName.first + ".tes")).string());
                break;
            case Shader::Type::tess_control:
                paths.emplace_back((shadersPaths / (shaderName.first + ".tcs")).string());
                break;
            case Shader::Type::geometry:
                paths.emplace_back((shadersPaths / (shaderName.first + ".gs")).string());
                break;
            case Shader::Type::compute:
                // ..paths.emplace_back((shadersPaths / (shaderName.first + ".cs")).string());
                break;
            default:
                break;
            }
        }

        std::cout << shaderName.first << "\n";
        if(!Managers::shaders.add_shader(shaderName.first, paths)){
            std::cerr << "Fail to load all shaders.\n";
            Managers::shaders.unbind();
            return false;
        }
        std::cout << "Shader: " << shaderName.first << " loaded. \n";
    }

    Managers::shaders.add_shader("colored-cloud", std::move(gl::ColoredCloudShader()));
    //    shadersPaths = currentPath / ".." / ".." / ".." / "cpp" / "toolbox" / "resources" / "shaders";
    //    shaderInit &= colorMeshShader.init();
    //    shaderInit &= texturedMeshShader.init();
    //    shaderInit &= texturedColorMeshShader.init();
    //    shaderInit &= texturedNormalsMeshShader.init();
    Managers::shaders.unbind();

    Managers::shaders.get_ptr("ch4/pbr")->debug_display();
    Managers::shaders.get_ptr("ch5/discard-pixels")->debug_display();

    return true;
}

bool DrawSampleWindow::init_textures(){

    // paths
    std::string path = std::filesystem::current_path().string() + "/resources/textures";

    // texture 2d
    std_v1<TextureLoadingInfo> texturesInfo= {
        {"container1",        "container.jpg"},
        {"container2",        "container2.png"},
        {"container2_spec",   "container2_specular.png"},
        {"brick",             "brick1.jpg"},
        {"wall",              "wall.jpg"},
        {"flower",            "flower.png"},
        {"smiley",            "smiley.png"},
        {"moss",              "moss.png"},
        {"fire",              "fire.png"},
        {"cement",            "cement.jpg"},
        {"ogre_diffuse",      "ogre_diffuse.png"},
        {"ogre_normalmap",    "ogre_normalmap.png"},
        {"mybrick-color",     "mybrick-color.png"},
        {"mybrick-normal",    "mybrick-normal.png"},
        {"mybrick-height",    "mybrick-height.png"},
        {"spot_texture",      "spot_texture.png"},
        {"me_textile",        "me_textile.png"},
        {"hardwood_diffuse",  "hardwood2_diffuse.jpg"},
    };

    std::cout << "# Load textures from path " << path << "\n";
    if(!Managers::textures.load_textures_from_directory(path, texturesInfo)){
        return false;
    }

    // cubemaps
    std::cout << "# Load cubemaps\n";
    bool loaded = true;
    loaded &= Managers::textures.load_cube_map(path + "/pisa/pisa_", {"posx.png","negx.png","posy.png","negy.png","posz.png","negz.png"},  "pisa", false);
    loaded &= Managers::textures.load_cube_map(path + "/grace/grace_",{"posx.hdr","negx.hdr","posy.hdr","negy.hdr","posz.hdr","negz.hdr"}, "grace", false);
    loaded &= Managers::textures.load_cube_map(path + "/grace-diffuse/grace-diffuse_",{"posx.hdr","negx.hdr","posy.hdr","negy.hdr","posz.hdr","negz.hdr"}, "grace-diffuse", false);
    if(!loaded){
        std::cerr << "Error during cubemaps loading.\n";
        return false;
    }

    // tbo
    // # texture 2d
    std::cout << "# Generate texture 2d TBO\n";
    loaded = true;
    loaded &= Managers::textures.generate_texture2d_tbo("me_textile",      "me_textile");
    loaded &= Managers::textures.generate_texture2d_tbo("cement",          "cement");
    loaded &= Managers::textures.generate_texture2d_tbo("brick",           "brick");
    loaded &= Managers::textures.generate_texture2d_tbo("moss",            "moss");
    loaded &= Managers::textures.generate_texture2d_tbo("mybrick-color",   "mybrick-color");
    loaded &= Managers::textures.generate_texture2d_tbo("mybrick-normal",  "mybrick-normal");
    loaded &= Managers::textures.generate_texture2d_tbo("mybrick-height",  "mybrick-height");
    loaded &= Managers::textures.generate_texture2d_tbo("spot_texture",    "spot_texture");
    loaded &= Managers::textures.generate_texture2d_tbo("ogre_diffuse",    "ogre_diffuse");
    loaded &= Managers::textures.generate_texture2d_tbo("ogre_normalmap",  "ogre_normalmap");
    loaded &= Managers::textures.generate_texture2d_tbo("hardwood_diffuse","hardwood_diffuse");
    loaded &= Managers::textures.generate_texture2d_tbo("flower",          "flower");

    if(!loaded){
        std::cerr << "Error during texture 2d TBO generation.\n";
        return false;
    }
    // # cubemaps
    std::cout << "# Generate cubemaps TBO\n";
    loaded = true;
    loaded &= Managers::textures.generate_cubemap_tbo("grace-diffuse", "grace-diffuse");
    loaded &= Managers::textures.generate_cubemap_tbo("grace", "grace");
    if(!loaded){
        std::cerr << "Error during cubemap TBO generation.\n";
        return false;
    }

    // others
    std::cout << "# Other\n";
    loaded &= Managers::textures.generate_texture2d_tbo("flower-projected",  "flower");

    return true;
}

bool DrawSampleWindow::init_models(){

    const auto currentPath = std::filesystem::current_path();
    const auto meshesPath = currentPath / "resources" / "meshes";

    std::string mesh = meshesPath.string();
    bool loaded = true;

    {
        Bench::start("models");

            loaded &= Managers::models.add_models({
                {"crysis",  mesh + "/crysis-nano-suit-2/scene.fbx"},
                {"pig",     mesh + "/pig/pig_triangulated.obj"},
                {"dragon",  mesh + "/dragon/dragon.obj"},
                {"ogre",    mesh + "/ogre/bs_ears.obj"},
                {"spot",    mesh + "/spot/spot_triangulated.obj"},
                {"fox",     mesh + "/low-poly-fox/source/animations.FBX"},
                {"bob",     mesh + "/bob/boblampclean.md5mesh"},
                {"bdragon", mesh + "/bdragon/source/bdragon.fbx"},
                {"alex",    mesh + "/alex/alex_breahting_idle.fbx"},
                {"rabbit",  mesh + "/rabbit/stanford_rabbit.obj"},
                {"storm",   mesh + "/storm/source/Storm_Ani.fbx"},
            });


        //        loaded = loaded && modelsM.add_model("crysis",  mesh + "crysis-nano-suit-2/scene.fbx");
        //        loaded = loaded && modelsM.add_model("storm",   mesh + "storm-ani/source/Storm_Ani.fbx");
        //        loaded = loaded && modelsM.add_model("pig",     mesh + "pig_triangulated.obj");
        //        loaded = loaded && modelsM.add_model("dragon",  mesh + "dragon.obj");
        //        loaded = loaded && modelsM.add_model("ogre",    mesh + "bs_ears.obj");
        //        loaded = loaded && modelsM.add_model("spot",    mesh + "spot_triangulated.obj");
        //        loaded = loaded && modelsM.add_model("fox",     mesh + "low-poly-fox-by-pixelmannen-animated/source/animations.FBX");
        //        loaded = loaded && modelsM.add_model("bob",     mesh + "bob/boblampclean.md5mesh");
        //        loaded = loaded && modelsM.add_model("bdragon", mesh + "assimp/bdragon/source/bdragon.fbx");
        //        loaded = loaded && modelsM.add_model("alex",    mesh + "alex/alex_breahting_idle.fbx");

        Bench::stop();
        Bench::display();
    }

    //    loaded = loaded && modelsM.add_model2("lord", mesh + "assimp/lord-inquisitor-servo-skull/source/lord.fbx");
    //    loaded = loaded && modelsM.add_model2("phoenix", mesh + "assimp/phoenix-bird/source/fly.fbx");
    //    loaded = loaded && modelsM.add_model2("ruby", mesh + "assimp/ruby-rose/source/rubyAnimated002.fbx");
    //    loaded = loaded && modelsM.add_model2("sci", mesh + "assimp/sci-fi-girl-v02-walkcycle-test/source/girl_walkcycle_test01.fbx");
    //    loaded = loaded && modelsM.add_model2("wolf", mesh + "assimp/wolf-with-animations/source/wolf.fbx"); // BAD FBX
    //    loaded = loaded && modelsM.add_model("bob",  mesh + "low-poly-fox-by-pixelmannen-animated/source/animations.FBX");

    return loaded;
}

bool DrawSampleWindow::init_drawers(){

    // add drawers
    bool drawerAdded = true;
    auto dm = &Managers::drawers;
    auto tm = &Managers::textures;
    auto mm = &Managers::models;

    // # procedural
    { // ## plane
        auto plane = std::make_shared<gl::PlaneDrawer>();
        plane->init(10,10);
        drawerAdded &= dm->add_drawer("notext-plane-10x10-drawer", plane);

        plane = std::make_shared<gl::PlaneDrawer>();
        plane->init(20,10);
        drawerAdded &= dm->add_drawer("notext-plane-20x10-drawer", plane);

        plane = std::make_shared<gl::PlaneDrawer>();
        plane->init(40,40);
        drawerAdded &= dm->add_drawer("notext-plane-40x40-drawer", plane);

        plane = std::make_shared<gl::PlaneDrawer>();
        plane->init(8,8,{tm->id("cement")});
        drawerAdded &= dm->add_drawer("floor-drawer", plane);

        plane = std::make_shared<gl::PlaneDrawer>();
        plane->init(8,8,{tm->id("me_textile")});
        drawerAdded &= dm->add_drawer("grid-floor-drawer", plane);

        plane = std::make_shared<gl::PlaneDrawer>();
        plane->init(8,8,{tm->id("mybrick-color"), tm->id("mybrick-normal"), tm->id("mybrick-height")});
        drawerAdded &= dm->add_drawer("multi-tex-plane-drawer", plane);
    }

    { // ## points
        // ...
    }

    { // ## torus
        auto torus = std::make_shared<gl::TorusDrawer>();
        torus->init();
        drawerAdded &= dm->add_drawer("torus-drawer", torus);
    }

    { // cube
        auto cube = std::make_shared<gl::CubeDrawer>();
        cube->init(2.f, {});
        drawerAdded &= dm->add_drawer("cube-drawer", cube);

        cube = std::make_shared<gl::CubeDrawer>();
        cube->init(2.f, {tm->id("brick")});
        drawerAdded &= dm->add_drawer("brick-cube-drawer", cube);

        cube = std::make_shared<gl::CubeDrawer>();
        cube->init(2.f, {tm->id("brick"), tm->id("moss")});
        drawerAdded &= dm->add_drawer("brick-moss-cube-drawer", cube);

        cube = std::make_shared<gl::CubeDrawer>();
        cube->init(2.f, {tm->id("cement"), tm->id("moss")});
        drawerAdded &= dm->add_drawer("cement-moss-cube-drawer", cube);
    }

    auto screenQuad  = std::make_shared<gl::FullscreenQuadDrawer>();
    screenQuad->init();
    drawerAdded &= dm->add_drawer("screen-quad-drawer", screenQuad);

    auto teapot = std::make_shared<gl::TeapotDrawer>();
    teapot->init();
    drawerAdded &= dm->add_drawer("teapot-drawer", teapot);

    auto sphere = std::make_shared<gl::SphereDrawer>();
    sphere->init(1.f, 20, 20);
    drawerAdded &= dm->add_drawer("sphere-drawer", sphere);

    auto axes = std::make_shared<gl::AxesDrawer>();
    axes->init();
    drawerAdded &= dm->add_drawer("axes-drawer", axes);

    auto frustum = std::make_shared<gl::FrustumDrawer>();
    frustum->init();
    drawerAdded &= dm->add_drawer("frustum-drawer", frustum);

    auto skybowDrawer = std::make_shared<gl::SkyboxDrawer>();
    skybowDrawer->init(tm->id("grace"));
    drawerAdded &= dm->add_drawer("skybox", skybowDrawer);

    // # loaded models
    auto model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("spot"),{tm->get_texture_info("spot_texture",{})});
    drawerAdded &= dm->add_drawer("spot-drawer", model);

    model->init(mm->get_model("spot"),{});
    drawerAdded &= dm->add_drawer("notext-spot-drawer", model);

    model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("ogre"),{tm->get_texture_info("ogre_diffuse",{}), tm->get_texture_info("ogre_normalmap",{})});
    drawerAdded &= dm->add_drawer("ogre-drawer", model);

    model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("pig"));
    drawerAdded &= dm->add_drawer("pig-drawer", model);

    model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("dragon"));
    drawerAdded &= dm->add_drawer("dragon-drawer", model);

    model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("crysis"));
    drawerAdded &= dm->add_drawer("crysis-drawer", model);

    model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("alex"));
    drawerAdded &= dm->add_drawer("alex-drawer", model);

    model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("storm"));
    model->update_animation(mm->get_model_ptr("storm")->animations[0].name, 0.f);
    drawerAdded &= dm->add_drawer("storm-drawer", model);

    model = std::make_shared<tool::gl::ModelDrawer>();
    model->init(mm->get_model("rabbit"));
    drawerAdded &= dm->add_drawer("rabbit-drawer", model);

    if(!drawerAdded){
        std::cerr << "[DrawSamples] Drawer not generated.\n";
    }
    return true;
}

bool DrawSampleWindow::init_samples(){

    // ch3
    samples["ch3Diffuse"]                   = std::make_unique<Ch3Diffuse>(&m_camera);
    samples["ch3TwoSide"]                   = std::make_unique<Ch3TwoSide>(&m_camera);
    samples["ch3Flat"]                      = std::make_unique<Ch3Flat>(&m_camera);
    samples["ch3Discard"]                   = std::make_unique<Ch3Discard>(&m_camera);
    samples["ch3Phong"]                     = std::make_unique<Ch3Phong>(&m_camera);
    // ch4
    samples["ch4PhongDirectionnalLight"]    = std::make_unique<Ch4PhongDirectionnalLight>(&m_camera);
    samples["ch4PhongMultiLights"]          = std::make_unique<Ch4PhongMultiLights>(&m_camera);
    samples["ch4PhongPerFragment"]          = std::make_unique<Ch4PhongPerFragment>(&m_camera);
    samples["ch4Cartoon"]                   = std::make_unique<Ch4Cartoon>(&m_camera);
    samples["ch4BlinnPhong"]                = std::make_unique<Ch4BlinnPhong>(&m_camera);
    samples["ch4PBR"]                       = std::make_unique<Ch4PBR>(&m_camera);
    // ch5
    samples["ch5SceneTexture"]              = std::make_unique<Ch5SceneTexture>(&m_camera);
    samples["ch5SceneMutliTexture"]         = std::make_unique<Ch5SceneMutliTexture>(&m_camera);
    samples["ch5DiscardPixels"]             = std::make_unique<Ch5DiscardPixels>(&m_camera);
    samples["ch5NormalMap"]                 = std::make_unique<Ch5NormalMap>(&m_camera);
    samples["ch5ParallaxMapping"]           = std::make_unique<Ch5ParallaxMapping>(&m_camera);
    samples["ch5SteepParallaxMapping"]      = std::make_unique<Ch5SteepParallaxMapping>(&m_camera);
    samples["ch5ReflectCubeMap"]            = std::make_unique<Ch5ReflectCubeMap>(&m_camera);
    samples["ch5RefractCubeMap"]            = std::make_unique<Ch5RefractCubeMap>(&m_camera);
    samples["ch5ProjectTexture"]            = std::make_unique<Ch5ProjectTexture>(&m_camera);
    samples["ch5DiffuseImageBasedLighting"] = std::make_unique<Ch5DiffuseImageBasedLighting>(&m_camera);
    samples["ch5SamplerObject"]             = std::make_unique<Ch5SamplerObject>(&m_camera);
    samples["ch5RenderToTexture"]           = std::make_unique<Ch5RenderToTexture>(&m_camera);
    samples["ch6EdgeDetectionFilter"]       = std::make_unique<Ch6EdgeDetectionFilter>(&m_camera);
    samples["ch6GaussianFilter"]            = std::make_unique<Ch6GaussianFilter>(&m_camera);
    samples["ch6HdrLightingToneMapping"]    = std::make_unique<Ch6HdrLightingToneMapping>(&m_camera);
    samples["ch6HdrBloom"]                  = std::make_unique<Ch6HdrBloom>(&m_camera);
    samples["ch6Deferred"]                  = std::make_unique<Ch6Deferred>(&m_camera);
    samples["ch6SSAO"]                      = std::make_unique<Ch6SSAO>(&m_camera);
    samples["ch6OIT"]                       = std::make_unique<Ch6OIT>(&m_camera);
    samples["ch7BezCurve"]                  = std::make_unique<Ch7BezCurve>(&m_camera);
    samples["ch7ShadeWire"]                 = std::make_unique<Ch7ShadeWire>(&m_camera);
    samples["ch7ScenePointSprite"]          = std::make_unique<Ch7ScenePointSprite>(&m_camera);
    samples["ch7Silhouette"]                = std::make_unique<Ch7Silhouette>(&m_camera);
    samples["ch8ShadowMap"]                 = std::make_unique<Ch8ShadowMap>(&m_camera);
    samples["ch8ShadowMap2"]                = std::make_unique<Ch8ShadowMap2>(&m_camera);

    demosName.reserve(samples.size());
    for(const auto &sample : samples){
        demosName.emplace_back(sample.first);
    }

    for(auto &sample : samples){
        std::cout << "init: " << sample.first << "\n";
        sample.second->init();
    }

    return true;
}


bool DrawSampleWindow::initialize_gl(){

    // flags
    glEnable(GL_MULTISAMPLE); // msaa
    glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

    // implot
    imPlotContext = ImPlot::CreateContext();

    // models
    std::cout << "Init models\n";
    if(!init_models()){
        return m_glInitialized = false;
    }

    // textures
    std::cout << "Init textures\n";
    if(!init_textures()){
        return m_glInitialized = false;
    }

    // shaders
    std::cout << "Init shaders\n";
    if(!init_shaders()){
        return m_glInitialized = false;
    }

    // camera
    std::cout << "Init camera\n";
    m_camera.set_direction(0.,0.,0.);

    std::cout << "Init drawers\n";
    init_drawers();

    std::cout << "Init samples\n";
    init_samples();

    VAO::unbind();

    return m_glInitialized = true;
}

void DrawSampleWindow::update_gl(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_STENCIL_TEST);

    // clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // polygon mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    gl::FBO::unbind();

    if(samples.count(demosName[currentDemo]) != 0){
        samples[demosName[currentDemo]]->draw();
    }
}

void DrawSampleWindow::post_update(){

    const auto elapsedSeconds = elapsed_secondes();

    // update lights
    float lightRotationSpeed = 1.5f;
    float deltaT = elapsedSeconds * lightRotationSpeed;
    auto ray= 20.f;
    Sample::alpha = deltaT;
    auto x = ray * cos(Sample::alpha);
    auto z = ray * sin(Sample::alpha);
    if(Sample::moveLight){
        geo::Pt3f offset = {0,5.f,0.f};
        Sample::mobileLightPos1 = geo::Pt4f{offset + geo::Pt3f{x,0,z}, 1.f};
        offset = {0,4.f,1.f};
        Sample::mobileLightPos2 = geo::Pt4f{offset + geo::Pt3f{-x,0,z}, 1.f};
    }

    auto mm = &Managers::models;
    auto dm = &Managers::drawers;

    // update animations
    if(auto model = mm->get_model("storm").lock()){
        if(auto drawer = dynamic_cast<gl::ModelDrawer*>(dm->get_drawer_ptr("storm-drawer")); drawer != nullptr){
            drawer->update_animation(model->animations[0].name, elapsedSeconds);
        }
    }

    // update current sample
    if(samples.count(demosName[currentDemo]) != 0){
        samples[demosName[currentDemo]]->update(elapsedSeconds);
    }
}

void DrawSampleWindow::update_imgui(){

    ImGui::Combo("Current sample:", &currentDemo, demosName);
    ImGui::Checkbox("Move lights:", &Sample::moveLight);

    if(samples.count(demosName[currentDemo]) != 0){
        samples[demosName[currentDemo]]->update_imgui();
    }

    if (ImGui::CollapsingHeader("Coords")){
        ImGui::SliderFloat("scale", &graphics::Sample::scale, 0.01f, 10.f, "ratio = %.2f");
        ImGui::SliderFloat("x", &graphics::Sample::x, -10.0f, 10.f, "ratio = %.2f");
        ImGui::SliderFloat("y", &graphics::Sample::y, -10.0f, 10.f, "ratio = %.2f");
        ImGui::SliderFloat("z", &graphics::Sample::z, -10.0f, 10.f, "ratio = %.2f");
        ImGui::SliderFloat("x1", &graphics::Sample::x1, -10.0f, 10.f, "ratio = %.2f");
        ImGui::SliderFloat("y1", &graphics::Sample::y1, -10.0f, 10.f, "ratio = %.2f");
        ImGui::SliderFloat("z1", &graphics::Sample::z1, -10.0f, 10.f, "ratio = %.2f");
        ImGui::SliderFloat("rx", &graphics::Sample::rx, -360.0f, 360.f, "ratio = %.2f");
        ImGui::SliderFloat("ry", &graphics::Sample::ry, -360.0f, 360.f, "ratio = %.2f");
        ImGui::SliderFloat("rz", &graphics::Sample::rz, -360.0f, 360.f, "ratio = %.2f");
    }

    //    if (ImGui::CollapsingHeader("Scatter Plots")) { // crash
    //        srand(0);
    //        static float xs1[100], ys1[100];
    //        for (int i = 0; i < 100; ++i) {
    //            xs1[i] = i * 0.01f;
    //            ys1[i] = xs1[i] + 0.1f * ((float)rand() / (float)RAND_MAX);
    //        }
    //        static float xs2[50], ys2[50];
    //        for (int i = 0; i < 50; i++) {
    //            xs2[i] = 0.25f + 0.2f * ((float)rand() / (float)RAND_MAX);
    //            ys2[i] = 0.75f + 0.2f * ((float)rand() / (float)RAND_MAX);
    //        }

    //        if (ImPlot::BeginPlot("Scatter Plot", NULL, NULL)) {
    //            ImPlot::PlotScatter("Data 1", xs1, ys1, 100);
    //            ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.25f);
    //            ImPlot::SetNextMarkerStyle(ImPlotMarker_Square, 6, ImVec4(0,1,0,0.5f), IMPLOT_AUTO, ImVec4(0,1,0,1));
    //            ImPlot::PlotScatter("Data 2", xs2, ys2, 50);
    //            ImPlot::PopStyleVar();
    //            ImPlot::EndPlot();
    //        }
    //    }
    //    if (ImGui::CollapsingHeader("Stairstep Plots")) {
    //        static float ys1[101], ys2[101];
    //        for (int i = 0; i < 101; ++i) {
    //            ys1[i] = 0.5f + 0.4f * sinf(50 * i * 0.01f);
    //            ys2[i] = 0.5f + 0.2f * sinf(25 * i * 0.01f);
    //        }

    //        if (ImPlot::BeginPlot("Stairstep Plot", "x", "f(x)")) {
    //            ImPlot::PlotStairs("Signal 1", ys1, 101, 0.01f);
    //            ImPlot::SetNextMarkerStyle(ImPlotMarker_Square, 2.0f);
    //            ImPlot::PlotStairs("Signal 2", ys2, 101, 0.01f);
    //            ImPlot::EndPlot();
    //        }
    //    }

}

void DrawSampleWindow::resize_windows(){
    // resize current sample
    if(samples.count(demosName[currentDemo]) != 0){
        samples[demosName[currentDemo]]->update_screen_size();
    }
}
