%% Generated by the Erlang ASN.1 compiler version:1.6.16
%% Purpose: Erlang record definitions for each named and unnamed
%% SEQUENCE and SET, and macro definitions for each value
%% definition,in module PKCS-1



-record('RSAPublicKey',{
modulus, publicExponent}).

-record('RSAPrivateKey',{
version, modulus, publicExponent, privateExponent, prime1, prime2, exponent1, exponent2, coefficient, otherPrimeInfos = asn1_NOVALUE}).

-record('OtherPrimeInfo',{
prime, exponent, coefficient}).

-record('Algorithm',{
algorithm, parameters = asn1_NOVALUE}).

-record('AlgorithmNull',{
algorithm, parameters}).

-record('RSASSA-PSS-params',{
hashAlgorithm, maskGenAlgorithm, saltLength = asn1_DEFAULT, trailerField = asn1_DEFAULT}).

-record('DigestInfo',{
digestAlgorithm, digest}).

-record('DigestInfoNull',{
digestAlgorithm, digest}).

-define('pkcs-1', {1,2,840,113549,1,1}).
-define('rsaEncryption', {1,2,840,113549,1,1,1}).
-define('id-RSAES-OAEP', {1,2,840,113549,1,1,7}).
-define('id-pSpecified', {1,2,840,113549,1,1,9}).
-define('id-RSASSA-PSS', {1,2,840,113549,1,1,10}).
-define('md2WithRSAEncryption', {1,2,840,113549,1,1,2}).
-define('md5WithRSAEncryption', {1,2,840,113549,1,1,4}).
-define('sha1WithRSAEncryption', {1,2,840,113549,1,1,5}).
-define('sha256WithRSAEncryption', {1,2,840,113549,1,1,11}).
-define('sha384WithRSAEncryption', {1,2,840,113549,1,1,12}).
-define('sha512WithRSAEncryption', {1,2,840,113549,1,1,13}).
-define('id-sha1', {1,3,14,3,2,26}).
-define('id-md2', {1,2,840,113549,2,2}).
-define('id-md5', {1,2,840,113549,2,5}).
-define('id-mgf1', {1,2,840,113549,1,1,8}).
