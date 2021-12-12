node('Windows') {
    stage('Fetch') {
        checkout([$class: 'GitSCM',
            branches: [[name: 'main']],
            doGenerateSubmoduleConfigurations: false,
            extensions: [[$class: 'CleanCheckout']],
            submoduleCfg: [],
            userRemoteConfigs: [[url: 'https://github.com/stevefortier/llamas']]
        ])
    }
    stage('Build') {
        dir('build') {
            bat('cmake ..')
            bat('cmake --build .')
            archiveArtifacts artifacts: 'src/Debug/**/*', fingerprint: true
        }
    }
}
