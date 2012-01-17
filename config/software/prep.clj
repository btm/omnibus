;;
;; Author:: Adam Jacob (<adam@opscode.com>)
;; Author:: Christopher Brown (<cb@opscode.com>)
;; Copyright:: Copyright (c) 2010 Opscode, Inc.
;; License:: Apache License, Version 2.0
;;
;; Licensed under the Apache License, Version 2.0 (the "License");
;; you may not use this file except in compliance with the License.
;; You may obtain a copy of the License at
;; 
;;     http://www.apache.org/licenses/LICENSE-2.0
;; 
;; Unless required by applicable law or agreed to in writing, software
;; distributed under the License is distributed on an "AS IS" BASIS,
;; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;; See the License for the specific language governing permissions and
;; limitations under the License.
;;

(software "prep"
          :steps [{:command "rm" :args ["-fR" "/opt/opscode"]}
                  {:command "mkdir" :args ["-p" "/opt/opscode/embedded/lib"]}
                  {:command "mkdir" :args ["-p" "/opt/opscode/embedded/bin"]}
                  {:command "mkdir" :args ["-p" "/opt/opscode/bin"]}]
                  {:command "cp" :args [(file-str *omnibus-home-dir* project-name ".changelog") "/opt/opscode/changelog"]})


